#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "utilitaires.h"

/* Conversion structure client => chaîne
Format chaîne : Nom[sep]Prénom[sep]Miles[sep]Ancienneté[sep]NoOrdre
[sep] : séparateur

Paramètres :
- typeClient *courant : pointeur vers structure client
- char separateur[] : chaîne séparant chaque variable dans la chaîne formatée

Résultat :
- Valeur de retour char * : chaîne formatée contenant les données du client passé en paramètre
*/
char *clientAChaine(typeClient *courant, char separateur[]){

	char chaine_tmp[MAX_CHAINE_SAISIE + 2], *chaine;
	char *nom, *prenom;
	int miles, anciennete, noordre;

	miles = courant->miles;
	anciennete = courant->anciennete;
	noordre = courant->noordre;
	nom = courant->nom;
	prenom = courant->prenom;

	sprintf(chaine_tmp, "%s%s%s%s%d%s%d%s%d\n", nom, separateur, prenom, separateur, miles, separateur, anciennete, separateur, noordre);

	chaine = (char *)malloc(sizeof(char)* strlen(chaine_tmp) + 1);
	strcpy(chaine, chaine_tmp);

	return chaine;

}


/* Conversion chaîne => structure client
Format chaîne : Nom[sep]Prénom[sep]Miles[sep]Ancienneté[sep]NoOrdre
[sep] : séparateur

Paramètres :
- char *chaine : chaîne formatée
- char separateur[] : chaîne séparant chaque variable dans la chaîne formatée

Résultat :
- Valeur de retour typeClient * : pointeur vers une nouvelle structure client
*/
typeClient *ChaineAClient(char *chaine, char separateur[]){

	typeClient *nouveau;
	int miles, anciennete, noordre, ret;
	char nom_tmp[MAX_CHAINE], prenom_tmp[MAX_CHAINE], format[MAX_CHAINE];
	char *nom = NULL, *prenom = NULL;

	//Séparation de la chaîne selon le séparateur
	sprintf(format, "%s%s%s%s%s%s%s%s%s", "%s", separateur, "%s", separateur, "%d", separateur, "%d", separateur, "%d");
	ret = sscanf(chaine, format, nom_tmp, prenom_tmp, &miles, &anciennete, &noordre);
	
	if (ret == 5) {
		nouveau = (typeClient *)malloc(sizeof(typeClient));
		nom = (char *)malloc(sizeof(char)* strlen(nom_tmp) + 1);
		strcpy(nom, nom_tmp);
		prenom = (char *)malloc(sizeof(char)* strlen(prenom_tmp) + 1);
		strcpy(prenom, prenom_tmp);

		nouveau->nom = nom;
		nouveau->prenom = prenom;
		nouveau->anciennete = anciennete;
		nouveau->miles = miles;
		nouveau->noordre = noordre;
		nouveau->priorite = miles / 1000 + anciennete - noordre;
	}
	else {
		nouveau = NULL;
	}

	return nouveau;

}


/* Affichage des nom et prénom d'un client

Paramètre :
- typeClient *courant : pointeur vers une structure client

Résultat :
- Affiche à l'écran Le nom et le prénom du client (séparé d'un espace)
*/
void affNomPrenomClient(typeClient *courant){

	printf("\n%s %s\n\n", courant->nom, courant->prenom);

}


/* Création d'un nouveau client via saisie utilisateur

Paramètre :
- int *maxNoOrdre : pointeur vers une variable contenant le dernier n° d'ordre attribué (le plus élevé)

Résultat :
- Valeur de retour typeClient *courant : pointeur vers une nouvelle structure client

*/
typeClient *saisirClient(int *maxNoOrdre){

	typeClient *nouveau;
	char *nom, *prenom;

	nouveau = (typeClient *)malloc(sizeof(typeClient));

	printf("Entrez le nom du client : ");
	nom = saisieChaine();
	suppEspace(nom);
	nouveau->nom = nom;

	printf("Entrez le prénom du client : ");
	prenom = saisieChaine();
	suppEspace(prenom);
	nouveau->prenom = prenom;


	printf("Entrez le nombre de miles du client : ");
	nouveau->miles = saisieEntier();

	printf("Entrez l'ancienneté du client : ");
	nouveau->anciennete = saisieEntier();

	*maxNoOrdre = *maxNoOrdre + 1;
	nouveau->noordre = *maxNoOrdre;
	nouveau->priorite = nouveau->miles / 1000 + nouveau->anciennete - nouveau->noordre;

	return nouveau;
}


/* Destruction d'un client : libération de la mémoire

Paramètres :
- typeClient *cliCour : pointeur vers vers la structure client à détruire

Résultats :
- Libération de la mémoire occupée par la structure
*/
void detruireClient(typeClient *cliCour) {
	free(cliCour->nom);
	free(cliCour->prenom);
	free(cliCour);
}