#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>

#include "client.h"

/* envoi et reception de message
 */
int envoie_recois_message(int socketfd) { //socket pour envoyer msg sur reseau
  char data[1024];
  memset(data, 0, sizeof(data));
  char message[1024];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin); //l'utilisateur entre un message qui est stocke dans message
  strcpy(data, "message: ");
  strcat(data, message); //dans data est stocke message : le_message_entre_par_utilisateur
  
  int write_status = write(socketfd, data, strlen(data)); //on ecrit jusqu'a strlen(data) octets dans le fichier socketfd et on ecrit ce qu'il y a dans data, write renvoie le nombre d'octets ecris
  if ( write_status < 0 ) { // si echec
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  memset(data, 0, sizeof(data)); //memset remplie les sizeof(data) premiers octets de la zone memoire pointe par data avec l'octet zero (deuxieme parametre) : mets que des zeros dans data -> reinitialisation
  int read_status = read(socketfd, data, sizeof(data)); //lit la reponse du serveur : on lit depuis socketfd et  on stock dans data
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}


int envoie_operateur_numeros(int socketfd){
  

  char data[1024];
  memset(data, 0, sizeof(data));

  char operateur[1024];
  printf("Votre operation, num1, num2 : ");
  fgets(operateur, 1024, stdin);  
  strcat(data, operateur);
  
 int write_status = write(socketfd, data, strlen(data)); //on ecrit jusqu'a strlen(data) octets dans le fichier socketfd et on ecrit ce qu'il y a dans data, write renvoie le nombre d'octets ecris
  if ( write_status < 0 ) { // si echec
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }
  memset(data, 0, sizeof(data)); //memset remplie les sizeof(data) premiers octets de la zone memoire pointe par data avec l'octet zero (deuxieme parametre) : mets que des zeros dans data -> reinitialisation
  int read_status = read(socketfd, data, sizeof(data)); //lit la reponse du serveur : on lit depuis socketfd et  on stock dans data
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  
  printf("operateur recu: %s\n", data);
 
  return 0;


}
     

int main() {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr; //sockaddr_in structure standard de c

  /*
   * Creation d'un socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0); //ouvre un socket 
  if ( socketfd < 0 ) {
    perror("socket"); //affiche la derniere erreur + le mot entre ""
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr)); //reinitialise l'adresse du serveur : server_addr (met que des zeros)
  //pour configurer la socket
  server_addr.sin_family = AF_INET; //reseau ip
  server_addr.sin_port = htons(PORT); //le port sur lequel on communique
  server_addr.sin_addr.s_addr = INADDR_ANY; //0.0.0.0 : tout le monde

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr)); //connecte la socket reference par le descripteur de fichier socketfd a l'adresse indique par server_addr (adresse du serveur). Le troisieme argument indique la taille du serveur :server_addr 
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }
  envoie_recois_message(socketfd);
  envoie_operateur_numeros(socketfd);

  close(socketfd);
}
