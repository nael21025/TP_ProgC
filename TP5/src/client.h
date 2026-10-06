#ifndef CLIENT_H
#define CLIENT_H

#define PORT 8089

#ifdef _WIN32
#include <winsock2.h>
typedef SOCKET socket_t;
#else
typedef int socket_t;
#endif

int envoie_recois_message(socket_t socketfd);
double envoie_operateur_numeros(socket_t socketfd, char op, double a, double b);

#endif