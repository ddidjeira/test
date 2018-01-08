#include <stdlib.h>
#include <stdio.h>
#include "pro.h"


BOOL vide (Regle R)
{
  if (R == NULL)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }
}

Regle creer ()
{
  return NULL;
}

Regle ajouterq (Regle R, char e[100])
{
  Regle nouvEl;
  Regle T;
  nouvEl = (element *) malloc (sizeof (element));
  strcpy (nouvEl->proposition, e);
  nouvEl->suivant = NULL;
  if (R == NULL)
    {
      R = nouvEl;
    }
  else
    {
      T = R;
      while (T->suivant != NULL)
	{
	  T = T->suivant;
	}
      T->suivant = nouvEl;
    }
  return R;
}

Regle conclusion (Regle R, char e[100])
{
  Regle new;
  Regle T;
  new = (element *) malloc (sizeof (element));
  strcpy (new->proposition, e);
  new->suivant = NULL;
  if (R == NULL)
    {
      R = new;
    }
  else
    {
      T = R;
      while (T->suivant != NULL)
	{
	  T = T->suivant;
	}
      T->suivant = new;
    }
  return R;
}


Regle supprimer (Regle R, char e[100])
{
    Regle T;
    if(R==NULL)
    {
        return EXIT_SUCCESS;
    }    
     else if (strcmp(R->proposition,e)==0)
    {
         T=R;
         R=R->suivant;
         free(R);
    }
           else
           {
                T=R;
                while (strcmp(T->suivant->proposition,e)==1)
                {
                    T=T->suivant;
                }
                free(R->suivant);
                R->suivant=R->suivant->suivant;
           }
           return R;
             
}


Regle supprimer_conclusion (Regle R)
{
  if (R != NULL)
    {
      if (R->suivant == NULL)
	{
	  free (R);
	  R = NULL;
	}
      else
	{
	  Regle T = R;
	  while (T->suivant->suivant != NULL)
	    {
	      T = T->suivant;
	    }
	  free (T->suivant);
	  T->suivant = NULL;
	}
    }
  return R;
}

void afficher (Regle R)
{
  if (vide (R))
    {
      printf ("*** Regle vide*** \n");
    }
  else
    {
      Regle T = R;
      printf ("[");
      while (T->suivant != NULL)
	{
	  printf ("%s ", T->proposition);
	  if (T->suivant->suivant != NULL)
	    {
	      printf ("et ");
	    }
	  else
	    {
	      printf ("=>");
	    }
	  T = T->suivant;
	}
      printf ("%s]\n", T->proposition);
    }
}

char * proposition_tete (Regle R)
{
  return R->proposition;
}

char * acces_conclusion (Regle R)
{
  while (R->suivant != NULL)
    {
      R = R->suivant;
    }
  return R->proposition;
}


BOOL existe (Regle R, char v[100])
{
  BOOL contient = FALSE;
  if(R==NULL)
  {
    return EXIT_SUCCESS;
  }
  else if (strcmp(R->proposition,v)==0)
  {
	    contient=TRUE;
	    return contient;
  }
  else
  {	    
      contient= existe(R->suivant,v);
      return contient;
  }
}


BC creation ()
{
  return NULL;
}

BC ajouteR (BC B, Regle R)
{

  BC T;
  T = B;
  BC new;
  new = (composant *) malloc (sizeof (composant));
  new->fait = R;
  new->next;
  if (empty (B))
    {
      B = new;
    }
  else
    {

      while (T->next != NULL)
	{
	  T = T->next;
	}
      T->next = new;
    }
  return B;
}


BOOL empty (BC B)
{
  if (B == NULL)
    {
      return TRUE;
    }
  else
    {
      return FALSE;
    }

}

void affiche (BC B)
{
  if (empty (B))
    {
      printf ("***la base est vide***\n");
    }
  else
    {
      BC T = B;
      while (!empty (B))
	{
	  printf ("[\n");
	  afficher (B->fait);
	  B = B->next;
	}
      printf ("]");
    }
  printf ("\n");
}

Regle en_tete (BC B)
{
  Regle K;
  K = B->fait;
  return K;
}
                
faits ajout (faits f, char e[100])
{
  faits nouv;
  faits g;
  nouv = (element *) malloc (sizeof (element));
  strcpy (nouv->proposition, e);
  nouv->suivant = NULL;
  if (f == NULL)
    {
      f = nouv;
    }
  else
    {
      g = f;
      while (g->suivant != NULL)
	{
	  g = g->suivant;
	}
      g->suivant = nouv;
    }
  return f;
}

void affichage (faits f)
{
  if (f==NULL)
    {
      printf ("*** Aucun fait*** \n");
    }
  else
    {
      Regle g = f;
      printf ("[");
      while (g->suivant != NULL)
	{
	  printf ("%s ", g->proposition);
	  g = g->suivant;
	}
      printf ("%s]\n", g->proposition);
    }
}

BOOL exist (faits f, char v[100])
{
  BOOL present = FALSE;
  faits g = f;
  while (g!=NULL && present == FALSE)
    {
      if (strcmp(proposition_tete (g),v)==0)
	{
	  present = TRUE;
	}
      else
	{
	  g = g->suivant;
	}
    }
  return present;
}

int nbElement(Regle R)
{
    int c;
    c=0;
    Regle T;
    if(!vide(R))
    {
        T=R;
        while(T!=NULL)
        {
            c=c+1;
            T=T->suivant;
        }
     }
     return c;
}
                 

faits Moteur(BC B, faits f)
{
    char a[100];
    int r;
    int n1;
    int n2;
    n2=0;
    char* c;
    do {    
        printf("ajouter les faits: ");
        scanf("%s", a);
        f=ajout(f,a);
        printf("voulez-vous ajouter d'autres faits?\n 0.Non\n ");
        scanf("%d", &r);
    } while( r != 0);
     affichage(f);
     
    if(empty(B))
    {
    printf("la base de faits est vide, veuillez saisir des faits\n");
    }
    else
    {
        BC K=B;
        faits h=f;
        while(B!=NULL)
        {
               if(existe(B->fait, h->proposition))
               {
                    n2=n2+1;
                    h=h->suivant;
                    n1=nbElement(B->fait);
                    c=acces_conclusion(B->fait);
               }
               B=B->next;
         }
         if (n2==n1-1)
         {
            if(!exist(h,c))
            {
                f=ajout(f, c);
            }
         }
         else
         {
         printf("les faits saisis ne sont pas vérifiéss\n");
         } 
      }
    return f;
}       
     

