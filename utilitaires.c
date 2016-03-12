#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilitaires.h"


/* Propose et vérifie la saisie d'un entier par l'utilisateur. Les saisies suivantes sont refusées :
- Saisie vide (\n)
- Saisie trop longue (> MAX_CHAINE)
- Saisie de valeur non entières

Résultat :
- Valeur de retour int : entier saisi par l'utilisateur
*/
int saisieEntier(){
	char entier[MAX_INT + 2];
	int ret, valeur;

	printf("> ");
	// lit un entier de max MAX_INT caractères
	// + 2 => pour les caractères '\n' et '\0' dont on ne veut pas tenir compte
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


/* Propose et vérifie la saisie d'une chaîne de caractère par l'utilisateur.
Les saisies suivant sont refusées :
- Saisie vide (\n)
- Saisie trop longue (> MAX_CHAINE_SAISIE)

Résultat :
- Valeur de retour char * : chaîne saisie par l'utilisateur
*/
char *saisieChaine(){
	char chaine_tmp[MAX_CHAINE_SAISIE + 2], *chaine;

	// On lit une chaîne de max MAX_CHAINE_SAISIE caractères
	// + 2 => pour les caractères '\n' et '\0' dont on ne veut pas tenir compte
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

	// Allocation dynamique pour la chaîne saisie
	chaine = (char *)malloc(sizeof(char) * strlen(chaine_tmp) + 1);
	strcpy(chaine, chaine_tmp);

	return chaine;
}


/* Supprime tous les espaces (" ") d'une chaîne de caratère.

Paramètre :
- La chaîne de caractère dont on veut supprimer les espaces

Résultat :
- La chaîne passée en paramètre est nettoyée des caractères espace
*/
void suppEspace(char *chaine) {
	char chaine_tmp[MAX_CHAINE + 2];
	int i, j;

	i = 0;
	j = 0;

	// Tant qu'on a pas atteint la fin de la chaîne
	while (chaine[i] != '\0') {
		// On recopie tous les caractère, sauf les espaces, de la chaîne vers une chaîne temporaire
		if (chaine[i] != ' ') {
			chaine_tmp[j] = chaine[i];
			j++;
		}
		i++;
	}

	chaine_tmp[j] = '\0';
	strcpy(chaine, chaine_tmp);
}
