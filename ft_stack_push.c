#include "stack.h"

t_stack *ft_stack_push(t_stack **sommet, const char *texte)
{
    t_stack *nouveau;
    int longueur;
    int i;

// calculer le nombre de caractere du texte a sauvegarder
    longueur = ft_strlen(texte);

// Alloue dynamiquement la mémoire nécessaire pour créer un nouveau nœud
    nouveau = malloc(sizeof(t_stack));

// Vérifie si l'allocation du nouveau nœud a échoué
    if (nouveau == NULL)
        return (NULL);

    // reserve la memoire neccessaire pour copié le texte
    nouveau->texte = malloc((longueur + 1 ) * sizeof(char));

    //verifié si l'allocation a echoué
    if(nouveau->texte ==NULL)
    {
        free(nouveau);
        return(NULL);
    }

    i = 0;
    //copie chaque caractere du texte original
    while(texte[i] != '\0')
    {
        nouveau->texte[i] = texte[i];
        i++;
    }
    // Ajoute le caractère de fin à la copie
    nouveau->texte[i] = '\0';

    //relie le nouveau neaud a l'ancien sommet de la pile
    nouveau->suivant  = *sommet;

    // Met à jour le sommet pour qu'il pointe vers le nouveau nœud
    *sommet = nouveau;

    return(nouveau);
}
