#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

typedef int BOOL;

typedef struct elem {
    char proposition[100];
    struct elem*suivant;
} element;

typedef element* faits;

typedef element*Regle;


typedef struct comp{
                    Regle fait;
                    struct comp* next;
                    }composant;               
            
typedef composant* BC;

BOOL vide(Regle l);
Regle creer();
Regle ajout(Regle R, char e[100]);
Regle ajouterq(Regle l, char e[100]);
Regle conclusion(Regle l, char e[100]);
Regle supprimer(Regle l, char e[100]);
Regle supprimer_conclusion(Regle l);
void afficher(Regle l);
void affiche(BC B);
char *proposition_tete(Regle l); // Cette fonction requiert que la liste ne soit pas vide
BOOL existe(Regle l, char v[100]);
char * acces_conclusion(Regle l);
BOOL empty(BC B);
BC ajouteR(BC B, Regle R);
Regle en_tete(BC B);
faits ajout (faits f, char e[100]);
void affichage (faits f);
BOOL exist (faits f, char v[100]);
int nbElement(faits f);
faits Moteur (BC B, faits f);
