//
//  stack.h
//  
//
//  Created by Bac Alexandra on 22/09/2019.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "liste.h"

typedef liste stack ;

// Type abstrait de données

void create_empty_stack(stack *ps) ;
bool is_empty_stack(stack s) ;
void push(Elt e, stack *ps);
Elt pop(stack *ps);
Elt top(stack s);

#endif /* stack_h */
