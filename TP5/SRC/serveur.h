#ifndef __SERVER_H__
#define __SERVER_H__

#define PORT 8089

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd);
int recois_numeros_calcule(int socketfd);
int renvoie_message(int client_socket_fd, char *data);
#endif
