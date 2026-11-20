

#include "stack.h"

int ft_stack_size(t_stack *sommet)
{
    int compteur;

    // Initialise le compteur à zéro
    compteur = 0;

    // Parcourt la pile jusqu'à atteindre la fin
    while (sommet != NULL)
    {
        // Compte le nœud actuel
        compteur++;

        // Passe au nœud suivant
        sommet = sommet->suivant;
    }

    // Retourne le nombre total de nœuds
    return (compteur);
}
