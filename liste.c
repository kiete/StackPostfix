//
//  liste.c
//  
//
//  Created by Bac Alexandra on 22/09/2019.
//

#include "liste.h"

// Type abstrait liste

liste creer_liste_vide ()
{ return NULL ; }

bool est_liste_vide (liste l)
{ return l == NULL ; }

liste ajouter (Elt e, liste l)
{
	maillon * tmp = malloc(sizeof(maillon)) ;
	tmp->elt = e ;
	tmp->suiv = l ;
	return tmp ;
}

Elt tete(liste l)
{
	assert(!est_liste_vide(l)) ;
	return l->elt ;
}

liste queue(liste l)
{
	assert(!est_liste_vide(l)) ;
	return l->suiv ;
}

// Gestion mémoire

Elt detruire_maillon(liste l)
{
	Elt tmp ;
	assert(!est_liste_vide(l)) ;
	tmp = l->elt ;
	free(l) ;
	return tmp ;
}

void detruire_liste(liste l)
{
	// Cas non terminal
	if (!est_liste_vide(l))
	{
		detruire_liste(queue(l)) ;
		free(l) ;
	}
}

// Fonctions utilitaires

void afficher_liste_rec(liste l)
{
	if (!est_liste_vide(l))
	{
		printf("%d->", l->elt) ;
		afficher_liste(queue(l)) ;
	}
}

void afficher_liste(liste l)
{
	afficher_liste_rec(l) ;
	printf("\n");
}
