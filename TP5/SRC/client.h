#ifndef __CLIENT_H__
#define __CLIENT_H__

#define PORT 8089

/* envoi et reception de message
 */
int envoie_recois_message(int socketfd);
int envoie_operateur_numeros(int socketfd);
void lire_dossier(char *notes_etu);
#endif
