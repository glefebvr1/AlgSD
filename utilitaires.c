#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitaires.h"


/* Propose et v�rifie la saisie d'un entier par l'utilisateur. Les saisies suivantes sont refus�es :
- Saisie vide (\n)
- Saisie trop longue (> MAX_CHAINE)
- Saisie de valeur non enti�res

R�sultat :
- Valeur de retour int : entier saisi par l'utilisateur
*/
int saisieEntier(){
	char entier[MAX_INT + 2];
	int ret, valeur;

	printf("> ");
	// lit un entier de max MAX_INT caract�res
	// + 2 => pour les caract�res '\n' et '\0' dont on ne veut pas tenir compte
	fgets(entier, MAX_INT + 2, stdin);
	ret = sscanf(entier, "%d", &valeur);

	// Tant que le nombre saisi est incorrect, on redemande la saisie
	while (ret != 1 || entier[strlen(entier) - 1] != '\n') {
		if (entier[strlen(entier) - 1] != '\n') {
			while (getchar() != '\n');
			puts("Nombre trop grand.");
		}
		else {
			puts("Saisie invalide.");
		}
		printf("> ");
		fgets(entier, MAX_INT + 2, stdin);
		ret = sscanf(entier, "%d", &valeur);
	}

	return valeur;
}


/* Propose et v�rifie la saisie d'une cha�ne de caract�re par l'utilisateur.
Les saisies suivant sont refus�es :
- Saisie vide (\n)
- Saisie trop longue (> MAX_CHAINE_SAISIE)

R�sultat :
- Valeur de retour char * : cha�ne saisie par l'utilisateur
*/
char *saisieChaine(){
	char chaine_tmp[MAX_CHAINE_SAISIE + 2], *chaine;

	// On lit une cha�ne de max MAX_CHAINE_SAISIE caract�res
	// + 2 => pour les caract�res '\n' et '\0' dont on ne veut pas tenir compte
	fgets(chaine_tmp, MAX_CHAINE_SAISIE + 2, stdin);
	while (chaine_tmp[0] == '\n' || chaine_tmp[strlen(chaine_tmp) - 1] != '\n') {
		if (chaine_tmp[strlen(chaine_tmp) - 1] != '\n') {
			while (getchar() != '\n');
			puts("Nombre de caracteres trop grand.");
		}
		else {
			puts("Saisie invalide.");
		}
		printf("> ");
		fgets(chaine_tmp, MAX_CHAINE_SAISIE + 2, stdin);
	}

	// Suppression du '\n'
	if (chaine_tmp[strlen(chaine_tmp) - 1] == '\n') {
		chaine_tmp[strlen(chaine_tmp) - 1] = '\0';
	}

	// Allocation dynamique pour la cha�ne saisie
	chaine = (char *)malloc(sizeof(char) * strlen(chaine_tmp) + 1);
	strcpy(chaine, chaine_tmp);

	return chaine;
}


/* Supprime tous les espaces (" ") d'une cha�ne de carat�re.

Param�tre :
- La cha�ne de caract�re dont on veut supprimer les espaces

R�sultat :
- La cha�ne pass�e en param�tre est nettoy�e des caract�res espace
*/
void suppEspace(char *chaine) {
	char chaine_tmp[MAX_CHAINE + 2];
	int i, j;

	i = 0;
	j = 0;

	// Tant qu'on a pas atteint la fin de la cha�ne
	while (chaine[i] != '\0') {
		// On recopie tous les caract�re, sauf les espaces, de la cha�ne vers une cha�ne temporaire
		if (chaine[i] != ' ') {
			chaine_tmp[j] = chaine[i];
			j++;
		}
		i++;
	}

	chaine_tmp[j] = '\0';
	strcpy(chaine, chaine_tmp);
}
