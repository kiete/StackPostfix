#include "liste.h"
#include "stack.h"
#include "errno.h"
#include <stdio.h>

#define T_MAX 80

// Evalue la valeur d'une expression postfixee
int evaluation_postfixe(char *expression);

// Applique une operation sur les 2 premiers elements de la pile
void operation_pile(stack *sp, char operation);

int main()
{
    int value;
    char test[T_MAX] = "1 4 + 5 * 3 2 * + 0 +";
    value = evaluation_postfixe(test);

    printf("value = %d\n", value);
    return 0;
}

void operation_pile(stack *sp, char operation){
    int r1,r2;
    switch (operation)
    {
    case '+':
        r1 = pop(sp);
        r2 = pop(sp);
        push(r1 + r2, sp);
        break;
    case '-':
        r1 = pop(sp);
        r2 = pop(sp);
        push(r1 - r2, sp);
        break;
    case '*':
        r1 = pop(sp);
        r2 = pop(sp);
        push(r1 * r2, sp);
        break;
    case '/':
        r1 = pop(sp);
        r2 = pop(sp);
        push(r1 / r2, sp);
        break;

    default:
        break;
    }
}

int evaluation_postfixe(char* expression){
    stack pile ;
    stack* sp;
    int n;
    int r1,r2;

    create_empty_stack(&pile);
    sp = &pile;

    char *p_debutChaine = expression;
    char *p_finChaine;
    do{

        n = strtol(p_debutChaine, &p_finChaine, 10);

// On ajoute l'element aussi si c'est 0
        if ((n != 0) || (*p_debutChaine == '0'))
        {
            push(n,sp);
        }else operation_pile(sp, *p_finChaine);

// On va placer p_debutChaine au premier element qui n'est pas un espace
        p_debutChaine = p_finChaine;
        p_debutChaine++;
        while (p_debutChaine != NULL && (*p_debutChaine == ' '))
        {
            p_debutChaine++;
        }

    } while (*p_debutChaine != 0);
    
    return pop(sp) ;
}

