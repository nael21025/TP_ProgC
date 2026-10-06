#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#define close_socket closesocket
#else
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define close_socket close
#endif

#include "client.h"

int envoyer(socket_t socketfd, const char *data)
{
#ifdef _WIN32
    return send(socketfd, data, (int)strlen(data), 0);
#else
    return (int)send(socketfd, data, strlen(data), 0);
#endif
}

int recevoir(socket_t socketfd, char *data, int taille)
{
#ifdef _WIN32
    return recv(socketfd, data, taille - 1, 0);
#else
    return (int)recv(socketfd, data, (size_t)taille - 1, 0);
#endif
}

double envoie_operateur_numeros(socket_t socketfd, char op, double a, double b)
{
    char data[1024];
    int taille;
    double resultat = 0;

    snprintf(data, sizeof(data), "calcule : %c %.6f %.6f", op, a, b);

    if (envoyer(socketfd, data) <= 0)
        return 0;

    memset(data, 0, sizeof(data));
    taille = recevoir(socketfd, data, sizeof(data));

    if (taille <= 0)
        return 0;

    data[taille] = '\0';
    printf("%s\n", data);

    sscanf(data, "calcule : %lf", &resultat);
    return resultat;
}

int envoie_recois_message(socket_t socketfd)
{
    char message[1000];
    char data[1024];
    int taille;

    printf("Votre message : ");

    if (fgets(message, sizeof(message), stdin) == NULL)
        return -1;

    message[strcspn(message, "\n")] = '\0';

    snprintf(data, sizeof(data), "message: %s", message);

    if (envoyer(socketfd, data) <= 0)
        return -1;

    memset(data, 0, sizeof(data));
    taille = recevoir(socketfd, data, sizeof(data));

    if (taille <= 0)
        return -1;

    data[taille] = '\0';
    printf("Message recu: %s\n", data);

    return 0;
}

double lire_note(int etudiant, int note)
{
    char chemin[200];
    FILE *fichier;
    double valeur = 0;

    snprintf(chemin, sizeof(chemin),
             "../etudiant/%d/note%d.txt", etudiant, note);

    fichier = fopen(chemin, "r");

    if (fichier == NULL)
        return 0;

    fscanf(fichier, "%lf", &valeur);
    fclose(fichier);

    return valeur;
}

void calculer_notes(socket_t socketfd)
{
    int etudiant;
    int note;
    double sommeClasse = 0;

    for (etudiant = 1; etudiant <= 5; etudiant++)
    {
        double sommeEtudiant = 0;

        for (note = 1; note <= 5; note++)
        {
            double valeur = lire_note(etudiant, note);
            sommeEtudiant = envoie_operateur_numeros(
                socketfd, '+', sommeEtudiant, valeur);
        }

        printf("Somme etudiant %d : %.2f\n",
               etudiant, sommeEtudiant);

        sommeClasse = envoie_operateur_numeros(
            socketfd, '+', sommeClasse, sommeEtudiant);
    }

    printf("Moyenne classe : %.2f\n",
           envoie_operateur_numeros(
               socketfd, '/', sommeClasse, 25));
}

int main()
{
    socket_t socketfd;
    struct sockaddr_in serveur;
    char commande[100];

#ifdef _WIN32
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Erreur WSAStartup\n");
        return 1;
    }
#endif

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

#ifdef _WIN32
    if (socketfd == INVALID_SOCKET)
#else
    if (socketfd < 0)
#endif
    {
        printf("Erreur socket\n");
        return 1;
    }

    memset(&serveur, 0, sizeof(serveur));
    serveur.sin_family = AF_INET;
    serveur.sin_port = htons(PORT);
    serveur.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(socketfd, (struct sockaddr *)&serveur,
                sizeof(serveur)) != 0)
    {
        printf("Impossible de se connecter au serveur\n");
        close_socket(socketfd);
        return 1;
    }

    while (1)
    {
        printf("\nTapez message, calcule, notes ou quit : ");

        if (fgets(commande, sizeof(commande), stdin) == NULL)
            break;

        commande[strcspn(commande, "\n")] = '\0';

        if (strcmp(commande, "quit") == 0)
            break;

        if (strcmp(commande, "notes") == 0)
        {
            calculer_notes(socketfd);
            continue;
        }

        if (strncmp(commande, "calcule :", 9) == 0)
        {
            char op;
            double a;
            double b;

            if (sscanf(commande, "calcule : %c %lf %lf",
                       &op, &a, &b) == 3)
            {
                envoie_operateur_numeros(socketfd, op, a, b);
            }
            else
            {
                printf("Exemple : calcule : + 23 45\n");
            }

            continue;
        }

        {
            char data[1024];
            int taille;

            snprintf(data, sizeof(data), "message: %s", commande);

            if (envoyer(socketfd, data) <= 0)
                break;

            memset(data, 0, sizeof(data));
            taille = recevoir(socketfd, data, sizeof(data));

            if (taille <= 0)
                break;

            data[taille] = '\0';
            printf("Message recu: %s\n", data);
        }
    }

    close_socket(socketfd);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}