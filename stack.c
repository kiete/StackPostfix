//
//  stack.c
//  
//
//  Created by Bac Alexandra on 22/09/2019.
//

#include "stack.h"

// Type abstrait de données

void create_empty_stack(stack *ps)
{
	*ps = creer_liste_vide() ;
}

bool is_empty_stack(stack s)
{
	return est_liste_vide(s) ;
}

void push(Elt e, stack *ps)
{
	*ps = ajouter(e, *ps) ;
}

Elt pop(stack *ps)
{
	maillon * tmp = queue(*ps) ;
	Elt e = detruire_maillon(*ps) ;
	*ps = tmp ;
	return e ;
}

Elt top(stack s)
{ return tete(s) ;}
