#include <stdlib.h>
#include <stdio.h>
#include "pro.h"

int
main (int argc, char *argv[])
{

  Regle R = NULL;
  BC B = NULL;
  faits f=NULL;
  int i;
  int n;

  int option;
  char prop[100];

  do
    {
      printf ("====================================\n\n");
      printf ("\nBASE\n");
      affiche (B);
      printf ("\n");
      printf ("choisir une option\n");
      printf ("1. Ajouter une proposition en fin de liste\n");
      printf ("2. creer la conclusion de la regle\n");
      printf ("3. Supprimer l'Ã©lÃ©ment en tÃªte \n");
      printf ("4. Tester si un Ã©lÃ©ment est dans liste\n");
      printf ("5. AccÃ©dera la premiÃ¨re valeur de a liste\n");
      printf ("6. AccÃ©de a la conclusion de la regle\n");
      printf ("7. Supprimer la conclusion de la regle\n");
      printf ("8. Ajouter une regle en fin de base\n");
      printf ("9. AccÃ©der ï¿½|  la regle en tÃªte de proposition\n");
      printf ("10. Moteur d'interfÃ©rence\n");
      printf ("0. Quitter\n");
      scanf ("%d", &option);


      switch (option)
	{
	case 1:
	  {
	    printf ("\n Entrez la chaine de caractÃre a ajouter:");
	    scanf ("%s", prop);
	    R = ajouterq (R, prop);
	    afficher (R);
	    break;
	  }
	case 2:
	  {
	    printf ("Entrer la conclusion de la regle: ");
	    scanf ("%s", prop);
	    R = conclusion (R, prop);
	    afficher (R);
	    break;
	  }
	case 3:
	  {
	    R = supprimert (R);
	    afficher (R);
	    break;
	  }
	case 4:
	  {
	    scanf ("%s", prop);
	    BOOL a = existe (R, prop);
	    if (a)
	      {
		printf ("La valeur est prÃ©sente\n");
	      }
	    else
	      {
		printf ("La valeur n'est pas prÃ©sente\n");
	      }
	    afficher (R);
	    break;
	  }
//          break;
	case 5:
	  {
	    printf ("La valeur en tÃªte est%s\n", proposition_tete (R));

	    break;
	  }
	case 6:
	  {
	    afficher (R);
	    printf ("La conclusion de la rÃ¨gle est%s\n",
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
	    printf ("La regle en tÃªte est:");
	    afficher (en_tete (B));
	    break;
	  }
	case 10:
	  {
	    f = Moteur (B, f);
	    break;
	  }
	}
    }
  while (option != 0);

  return EXIT_SUCCESS;
}
