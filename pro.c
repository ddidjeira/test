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


Regle supprimert (Regle l)
{
  Regle p;
  if (l == NULL)
    {
      p = NULL;
    }
  else
    {
      p = l->suivant;
      free (l);
    }
  return p;
}

Regle supprimer_conclusion (Regle l)
{
  if (l != NULL)
    {
      if (l->suivant == NULL)
	{
	  free (l);
	  l = NULL;
	}
      else
	{
	  Regle p = l;
	  while (p->suivant->suivant != NULL)
	    {
	      p = p->suivant;
	    }
	  free (p->suivant);
	  p->suivant = NULL;
	}
    }
  return l;
}

void afficher (Regle l)
{
  if (vide (l))
    {
      printf ("*** Regle vide*** \n");
    }
  else
    {
      Regle p = l;
      printf ("[");
      while (p->suivant != NULL)
	{
	  printf ("%s ", p->proposition);
	  if (p->suivant->suivant != NULL)
	    {
	      printf ("et ");
	    }
	  else
	    {
	      printf ("=>");
	    }
	  p = p->suivant;
	}
      printf ("%s]\n", p->proposition);
    }
}

char * proposition_tete (Regle l)
{
  return l->proposition;
}

char * acces_conclusion (Regle l)
{
  while (l->suivant != NULL)
    {
      l = l->suivant;
    }
  return l->proposition;
}

BOOL existe (Regle l, char v[100])
{
  BOOL contient = FALSE;
  Regle p = l;
  while (!vide (p) && contient == FALSE)
    {
      if (strcmp(proposition_tete(l),v)==0)
	{
	  contient = TRUE;
	}
      else
	{
	  p = p->suivant;
	}
    }
  return contient;
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
  Regle g = f;
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

int nbElement(faits f)
{
    int c=0;
    faits g;
    if(f==NULL)
    {
        g=f;
        while(g!=NULL)
        {
            c=c+1;
            g=g->suivant;
        }
     }
}
                 
 faits Moteur(BC B, faits f)
{
    char a[100];
    int r;
    char* c;
    int n1;
    int n2;
    n2=0;
    BOOL b;
    f=NULL;
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
    
        while(B!=NULL)
        {
            n1=nbElement(B->fait);
            
            while(B->fait->suivant->suivant !=NULL)
            {
               existe(f, B->fait->proposition);
               n2=n2+1;
               B->fait=B->fait->suivant;
             }
             B=B->next;
        }
        if (n2==n1)
        {
            c=acces_conclusion(B->fait);
            f=ajout(f, c);
        }
        else
        {
        printf("les faits saisis ne sont pas vérifiés");
        } 
    }
    return f;
}       

