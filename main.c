
#include "stack.h"

// Supprime le retour à la ligne saisi avec fgets
static void ft_remove_newline(char *texte)
{
    int i;

    i = 0;
    while (texte[i] != '\0')
    {
        if (texte[i] == '\n')
        {
            texte[i] = '\0';
            return;
        }
        i++;
    }
}

// Ajoute du texte à la fin du document
static int ft_document_add(char **document, t_stack **historique,
                           const char *ajout)
{
    char *nouveau;
    int longueur_document;
    int longueur_ajout;
    int i;

    longueur_document = ft_strlen(*document);
    longueur_ajout = ft_strlen(ajout);

    // Ne fait rien si aucun texte n'est ajouté
    if (longueur_ajout == 0)
        return (1);

    // Alloue la mémoire pour le nouveau document
    nouveau = malloc(longueur_document + longueur_ajout + 1);
    if (nouveau == NULL)
        return (0);

    // Copie le document actuel
    i = 0;
    while (i < longueur_document)
    {
        nouveau[i] = (*document)[i];
        i++;
    }

    // Ajoute le nouveau texte à la suite
    while (ajout[i - longueur_document] != '\0')
    {
        nouveau[i] = ajout[i - longueur_document];
        i++;
    }

    // Termine la chaîne de caractères
    nouveau[i] = '\0';

    // Sauvegarde l'ancien document avant de le modifier
    if (ft_stack_push(historique, *document) == NULL)
    {
        free(nouveau);
        return (0);
    }

    // Remplace l'ancien document par le nouveau
    free(*document);
    *document = nouveau;

    return (1);
}

int main(void)
{
    t_stack *historique;
    char *document;
    char *restaure;
    char choix[32];
    char ajout[1024];

    // Initialise la pile et le document vide
    historique = NULL;
    document = malloc(1);
    if (document == NULL)
        return (1);
    document[0] = '\0';

    while (1)
    {
        printf("\n===== MINI EDITEUR =====\n");
        printf("1. Ajouter du texte\n");
        printf("2. Afficher le document\n");
        printf("3. Annuler (Undo)\n");
        printf("4. Quitter\n");
        printf("Votre choix : ");

        if (fgets(choix, sizeof(choix), stdin) == NULL)
            break;

        if (choix[0] == '1')
        {
            printf("Texte a ajouter : ");
            if (fgets(ajout, sizeof(ajout), stdin) == NULL)
                break;

            ft_remove_newline(ajout);

            if (ft_document_add(&document, &historique, ajout))
                printf("Texte ajoute avec succes.\n");
            else
                printf("Erreur : impossible d'ajouter le texte.\n");
        }
        else if (choix[0] == '2')
        {
            printf("\nDocument actuel :\n%s\n", document);
        }
        else if (choix[0] == '3')
        {
            restaure = ft_stack_pop(&historique);

            if (restaure == NULL)
                printf("Aucune action a annuler.\n");
            else
            {
                free(document);
                document = restaure;
                printf("Derniere modification annulee.\n");
            }
        }
        else if (choix[0] == '4')
        {
            break;
        }
        else
        {
            printf("Choix invalide.\n");
        }
    }

    // Libère le document et toute l'historique
    free(document);
    ft_stack_clear(&historique);

    printf("Editeur ferme.\n");
    return (0);
}
