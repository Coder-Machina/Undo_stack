
#ifndef STACK_H
# define STACK_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
    char *texte;
    struct s_stack *suivant;
} t_stack;

// Fonctions de gestion de la pile
t_stack *ft_stack_push(t_stack **sommet, const char *texte);
char *ft_stack_pop(t_stack **sommet);
int ft_stack_size(t_stack *sommet);
void ft_stack_clear(t_stack **sommet);

// Fonction de calcul de longueur
int ft_strlen(const char *texte);

#endif
