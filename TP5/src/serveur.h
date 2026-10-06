#ifndef SERVEUR_H
#define SERVEUR_H

#define PORT 8089

#ifdef _WIN32
#include <winsock2.h>
typedef SOCKET socket_t;
#else
typedef int socket_t;
#endif

int renvoie_message(socket_t client_socket_fd, const char *data);
int recois_numeros_calcule(socket_t client_socket_fd, const char *data);

#endif