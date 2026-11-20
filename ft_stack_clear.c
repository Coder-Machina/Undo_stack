
#include "stack.h"

void ft_stack_clear(t_stack **sommet)
{
    t_stack *temp;

    // Vérifie si le pointeur vers le sommet est valide
    if (sommet == NULL)
        return;

    // Parcourt tous les nœuds de la pile
    while (*sommet != NULL)
    {
        // Conserve le nœud actuel
        temp = *sommet;

        // Déplace le sommet vers le nœud suivant
        *sommet = temp->suivant;

        // Libère le texte sauvegardé
        free(temp->texte);

        // Libère le nœud actuel
        free(temp);
    }
}

