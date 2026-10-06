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

#include "serveur.h"

int renvoie_message(socket_t client_socket_fd, const char *data)
{
#ifdef _WIN32
    return send(client_socket_fd, data, (int)strlen(data), 0) > 0 ? 0 : 1;
#else
    return send(client_socket_fd, data, strlen(data), 0) > 0 ? 0 : 1;
#endif
}

int recois_numeros_calcule(socket_t client_socket_fd, const char *data)
{
    char op;
    double a;
    double b;
    double resultat = 0;
    char reponse[200];

    if (sscanf(data, "calcule : %c %lf %lf", &op, &a, &b) != 3)
        return 1;

    switch (op)
    {
        case '+':
            resultat = a + b;
            break;

        case '-':
            resultat = a - b;
            break;

        case '*':
            resultat = a * b;
            break;

        case '/':
            if (b == 0)
            {
                renvoie_message(client_socket_fd,
                                "erreur : division par zero");
                return 1;
            }
            resultat = a / b;
            break;

        case '%':
            if ((long long)b == 0)
            {
                renvoie_message(client_socket_fd,
                                "erreur : modulo par zero");
                return 1;
            }
            resultat = (double)((long long)a % (long long)b);
            break;

        case '&':
            resultat = (double)((long long)a & (long long)b);
            break;

        case '|':
            resultat = (double)((long long)a | (long long)b);
            break;

        case '~':
            resultat = (double)(~(long long)a);
            break;

        default:
            renvoie_message(client_socket_fd,
                            "erreur : operateur inconnu");
            return 1;
    }

    snprintf(reponse, sizeof(reponse),
             "calcule : %.6f", resultat);

    return renvoie_message(client_socket_fd, reponse);
}

void gerer_client(socket_t client)
{
    char data[1024];

    while (1)
    {
        int taille;

        memset(data, 0, sizeof(data));

#ifdef _WIN32
        taille = recv(client, data, sizeof(data) - 1, 0);
#else
        taille = (int)recv(client, data, sizeof(data) - 1, 0);
#endif

        if (taille <= 0)
            break;

        data[taille] = '\0';

        if (strncmp(data, "calcule :", 9) == 0)
        {
            recois_numeros_calcule(client, data);
        }
        else if (strncmp(data, "message:", 8) == 0)
        {
            char reponse[1000];

            printf("Message recu: %s\n", data);
            printf("Reponse serveur : ");

            if (fgets(reponse, sizeof(reponse), stdin) == NULL)
                strcpy(reponse, "OK");

            reponse[strcspn(reponse, "\n")] = '\0';
            renvoie_message(client, reponse);
        }
    }

    close_socket(client);
}

int main()
{
    socket_t serveur;
    struct sockaddr_in adresse;

#ifdef _WIN32
    WSADATA wsa;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Erreur WSAStartup\n");
        return 1;
    }
#endif

    serveur = socket(AF_INET, SOCK_STREAM, 0);

#ifdef _WIN32
    if (serveur == INVALID_SOCKET)
#else
    if (serveur < 0)
#endif
    {
        printf("Erreur socket\n");
        return 1;
    }

    memset(&adresse, 0, sizeof(adresse));
    adresse.sin_family = AF_INET;
    adresse.sin_port = htons(PORT);
    adresse.sin_addr.s_addr = INADDR_ANY;

    if (bind(serveur, (struct sockaddr *)&adresse,
             sizeof(adresse)) != 0)
    {
        printf("Erreur bind\n");
        close_socket(serveur);
        return 1;
    }

    if (listen(serveur, 10) != 0)
    {
        printf("Erreur listen\n");
        close_socket(serveur);
        return 1;
    }

    printf("Serveur en attente de connexions...\n");

    while (1)
    {
        socket_t client;

        client = accept(serveur, NULL, NULL);

#ifdef _WIN32
        if (client == INVALID_SOCKET)
#else
        if (client < 0)
#endif
            continue;

        printf("Client connecte\n");
        gerer_client(client);
        printf("Client deconnecte\n");
    }

    close_socket(serveur);

#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}