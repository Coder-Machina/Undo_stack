
#include "stack.h"

char *ft_stack_pop(t_stack **sommet)
{
    t_stack *ancien;
    char *texte;

    // Vérifie si la pile est vide ou invalide
    if (sommet == NULL || *sommet == NULL)
        return (NULL);

    // Conserve l'adresse du premier nœud
    ancien = *sommet;

    // Récupère l'adresse du texte à retourner
    texte = ancien->texte;

    // Déplace le sommet vers le nœud suivant
    *sommet = ancien->suivant;

    // Libère le nœud retiré
    free(ancien);

    // Retourne le texte sans le libérer
    return (texte);
}
