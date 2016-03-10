#include "utilitaires.h"


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
int Saisie_Entier(){
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

/*
Propose et vérifie la saisie d'une chaîne de caractère par l'utilisateur. Une allocation sera faite pour (strlen + 1) Les saisies suivant sont refusées :
- Saisie vide (\n)
- Saisie trop longe (> 100 caractères)

Paramètres :
- Aucun

Résultat :
- Retourne un entier
*/
char *Saisie_Chaine(){
	char chaine_tmp[MAX_CHAINE_SAISIE + 2], *chaine;

	// lit une chaîne de max MAX_CHAINE_SAISIE caractères
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

	// Copie de la chaîne dans un tableau dynamique
	chaine = (char *)malloc(sizeof(char) * strlen(chaine_tmp) + 1);
	strcpy(chaine, chaine_tmp);

	return chaine;
}


/*
Supprime tous les espaces (" ") d'une chaîne de caratère.

Paramètre :
- La chaîne de caractère dont on veut supprimer les espaces

Résultat :
- La chaîne n'a plus d'espace entre les caractères
*/

void suppEspace(char *chaine) {



}
