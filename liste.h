//
//  liste.h
//  
//
//  Created by Bac Alexandra on 22/09/2019.
//

#ifndef liste_h
#define liste_h

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Elt ;
typedef int bool ;
struct zmaillon {
	Elt elt ;
	struct zmaillon *suiv ;
} ;
typedef struct zmaillon maillon ;
typedef struct zmaillon * liste;

// Type abstrait liste

liste creer_liste_vide ();

bool est_liste_vide (liste l);

liste ajouter (Elt e, liste l);

Elt tete(liste l);

liste queue(liste l);

// Gestion mémoire

Elt detruire_maillon(liste l);

void detruire_liste(liste l);

// Fonctions utilitaires

void afficher_liste(liste l);

#endif /* liste_h */
