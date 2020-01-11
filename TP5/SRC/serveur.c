/* Fichier: serveur.c
 * Communication client-serveur
 * Auteurs: John Samuel, ...
 */

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"

/* renvoyer un message (*data) au client (client_socket_fd)
 */

//socket pour communiquer sur reseau : file descripteur
int renvoie_message(int client_socket_fd, char *data) { //VOID * : pointeur sur n'importe quoi 
  int data_size = write (client_socket_fd, data, strlen(data)); ////on ecrit jusqu'a strlen(data) octets dans le socket client_socket_fd et on ecrit ce qu'il y a dans data, write renvoie le nombre d'octets ecris
      //on envoie ce qu'il y a dans data au client
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. Ensuite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len); //on accepte un client, accept nous renvoie la socket a laquelle on est connecte et remplie les donnes du client : client_addr
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data)); //reinistialise data
// que si on a un client, sinon on est bloque ligne 42 (accept est un appelle bloquant)
  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data)); //on lit depuis client_socket_fd et on stocke dans data : on lit ce qui est envoye par le client
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
        
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s", code); //sscanf lit dans une chaine de caractere jusqu'au premier espace : lit dans data le premier mot et mets dans code 

  //Si le message commence par le mot: 'message:' 
  if (strcmp(code, "message:") == 0) { // si le code = "message: "
    printf("serveur, saisissez un message: ");
    fgets(data, 1024, stdin);
    renvoie_message(client_socket_fd, data); //on renvoie le message data dans le socket
  }

  return client_socket_fd;
}





int recois_numeros_calcule(int socketfd){
  struct sockaddr_in client_addr;
  char data[1024];
   int client_addr_len = sizeof(client_addr);

 int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len); //on accepte un client, accept nous renvoie la socket a laquelle on est connecte et remplie les donnes du client : client_addr
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }


  memset(data, 0, sizeof(data)); //reinistialise data
// que si on a un client, sinon on est bloque ligne 42 (accept est un appelle bloquant)
  //lecture de données envoyées par un client
  int data_size = read (socketfd, (void *) data, sizeof(data)); //on lit depuis socket_fd et on stocke dans data : on lit ce qui est envoye par le client
      
  if (data_size < 0) {
    printf("hola\n");
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
        
  printf ("Message recu: %s\n", data);
  char code_op;
  char* note;
  int resultat;
  int verif = sscanf(data, "%c %s", &code_op,note); 
  printf("%s\n", note);
  if ((verif >2) || (verif<2)) {
      perror("erreur lecture");
      return(EXIT_FAILURE);
    }
    
//question 2
/*
  if (code_op == '+'|| code_op == '-'|| code_op == '*'|| code_op == '/') { // si le premier element de data est un operateur
    switch (code_op) {
      
    case '+' : resultat = num1 + num2;
    sprintf(data, "%d", resultat);
    renvoie_message(socketfd, data);
    break;
    
    case '-' : resultat = num1 - num2;
    sprintf(data, "%d", resultat);
    renvoie_message(socketfd, data);
    break;
    case '*' : resultat = num1 * num2;
    sprintf(data, "%d", resultat);
    renvoie_message(socketfd, data);
    break;
    case '/' : resultat = num1 / num2;
    sprintf(data, "%d", resultat);
    renvoie_message(socketfd, data);
    break;
    }
  }
  */
  
  //question 3 
  int i = 0;
    for (i=0 ; i<4; i++){
      resultat += note[i];
    }
    sprintf(data, "%d", resultat);
    renvoie_message(socketfd, data);
  //fermer le socket 
  close(socketfd);  
}

int main() {

  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'un socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_STREAM est du TCP : en mode connecte (connecte au serveur) != udp (pas de connexion entre client et serveur)
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY; //In accepte les connexions de n'importe ou 

  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr)); //on associe le port et l'ip 
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  listen(socketfd, 10); //10 clients sur le serveur a la fois a l'instant t
  int client_fd = recois_numeros_calcule(socketfd);
  //recois_numeros_calcule(client_fd);
  //recois_envoie_message(socketfd);
  return 0;
}
