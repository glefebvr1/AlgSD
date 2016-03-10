/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : fonctions utilitaires et définitions

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_INT 10
#define MAX_CHAINE 100
#define MAX_CHAINE_SAISIE 100


/*
Propose et vérifie la saisie d'un entier par l'utilisateur. Les saisies suivant sont refusées :
- Saisie vide (\n)
- Saisie trop longe (> 10 chiffres)
- Saisie de valeur non entières

Paramètres :
- Aucun

Résultat :
- Retourne un entier
*/
int saisieEntier();


/*
Propose et vérifie la saisie d'une chaîne de caractère par l'utilisateur. Une allocation sera faite pour (strlen + 1) Les saisies suivant sont refusées :
- Saisie vide (\n)
- Saisie trop longe (> 100 caractères)

Paramètres :
- Aucun

Résultat :
- Retourne un entier
*/
char *saisieChaine();



/*
Supprime tous les espaces (" ") d'une chaîne de caratère.

Paramètre :
- La chaîne de caractère dont on veut supprimer les espaces

Résultat :
- La chaîne n'a plus d'espace entre les caractères
*/
void suppEspace(char *chaine);
