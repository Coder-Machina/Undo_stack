#include "stack.h"

// fonction qui calculer la longeur du texte
int ft_strlen(const char *texte)
{
    int i=0;
    // parcourir le texte jusqu"a la fin
    while(texte[i] != '\0')
        i++;

    //retourne le nombre de caractere
    return(i);
}
