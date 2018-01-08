#include <stdlib.h>
#include <stdio.h>
#include "pro.h"

int
main (int argc, char *argv[])
{

  Regle R = NULL;
  BC B = NULL;
  faits f=NULL;
  int option;
  char prop[100];

  do
    {
      printf ("====================================\n\n");
      printf ("\nBASE\n");
      affiche (B);
      printf ("\n");
      printf ("choisir une option\n");
      printf ("1. Ajouter une proposition en fin de règle\n");
      printf ("2. creer la conclusion de la règle\n");
      printf ("3. Supprimer une proposition de la règle \n");
      printf ("4. Tester si une proposition est dans la règle\n");
      printf ("5. Accéder à la première proposition de la règle\n");
      printf ("6. Accéder à la conclusion de la règle\n");
      printf ("7. Supprimer la conclusion de la règle\n");
      printf ("8. Ajouter une règle en fin de base\n");
      printf ("9. Accéder à la règle se trouvant en tête de la base\n");
      printf ("10. Moteur d'interférence\n");
      printf ("0. Quitter\n");
      scanf ("%d", &option);


      switch (option)
	{
	case 1:
	  {
	    printf ("\n Entrez la chaine de caractère à ajouter:");
	    scanf ("%s", prop);
	    R = ajouterq (R, prop);
	    afficher (R);
	    break;
	  }
	case 2:
	  {
	    printf ("Entrer la conclusion de la règle: ");
	    scanf ("%s", prop);
	    R = conclusion (R, prop);
	    afficher (R);
	    break;
	  }
	case 3:
	  {
	    printf("Entrez la proposition à supprimer; ");
	    scanf("%s", prop);
	    R = supprimer (R, prop);
	    afficher (R);
	    break;
	  }
	case 4:
	  {
	    printf("Entrez la proposition à rechercher: ");
	    scanf ("%s", prop);
	    BOOL a = existe (R, prop);
	    if (a)
	      {
		printf ("La proposition est présente\n");
	      }
	    else
	      {
		printf ("La proposition n'est pas présente\n");
	      }
	    afficher (R);
	    break;
	  }
//          break;
	case 5:
	  {
	    printf ("La proposition en tête est %s\n", proposition_tete (R));

	    break;
	  }
	case 6:
	  {
	    afficher (R);
	    printf ("La conclusion de la règle est %s\n",
		    acces_conclusion (R));
	    break;
	  }
	case 7:
	  {
	    R = supprimer_conclusion (R);
	    afficher (R);
	    break;
	  }
	case 8:
	  {
	    B = ajouteR (B, R);
	    R = NULL;
	    break;
	  }
	case 9:
	  {
	    printf ("La regle en tête de la base est:");
	    afficher (en_tete (B));
	    break;
	  }
	case 10:
	  {
	    f = Moteur (B, f);
	    printf("\n\n la nouvelle base de faits est:\n");
	    affichage(f);
	    f=NULL;
	    break;
	  }
	}
    }
  while (option != 0);

  return EXIT_SUCCESS;
}
