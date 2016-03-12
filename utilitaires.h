/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : fonctions utilitaires et définitions

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************/

#define MAX_INT 10
#define MAX_CHAINE 100
#define MAX_CHAINE_SAISIE 100


/* Propose et vérifie la saisie d'un entier par l'utilisateur. Les saisies suivantes sont refusées :
- Saisie vide (\n)
- Saisie trop longue (> MAX_CHAINE)
- Saisie de valeur non entières

Résultat :
- Valeur de retour int : entier saisi par l'utilisateur
*/
int saisieEntier();


/* Propose et vérifie la saisie d'une chaîne de caractère par l'utilisateur. 
Les saisies suivant sont refusées :
- Saisie vide (\n)
- Saisie trop longue (> MAX_CHAINE_SAISIE)

Résultat :
- Valeur de retour char * : chaîne saisie par l'utilisateur
*/
char *saisieChaine();


/* Supprime tous les espaces (" ") d'une chaîne de caratère.

Paramètre :
- La chaîne de caractère dont on veut supprimer les espaces

Résultat :
- La chaîne passée en paramètre est nettoyée des caractères espace
*/
void suppEspace(char *chaine);
