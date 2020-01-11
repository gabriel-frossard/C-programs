#ifndef REPERTOIRE_H  
#define REPERTOIRE_H 
//creation d'une liste chainee
typedef struct Dossier Dossier;
struct Dossier
{
    char *rep;
    Dossier *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Dossier *premier;
};

Liste *initialisation(char *rep);
void insertion(Liste *liste, char *rep);
void suppression(Liste *liste);
void afficherListe(Liste *liste);

void lire_dossier(char *);
void lire_dossier_recursif(char *);
void lire_dossier_iteratif(char *);

#endif
