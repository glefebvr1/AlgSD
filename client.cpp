#include "client.h"
#include "fileattente.h"
#include "utilitaires.h"

/* Conversion client a une chaine formatée
Format ici : Nom Prénom Miles Ancienneté NoOrdre

Paramètre :
- Le client que l'on désire transformée en chaîne
- Le caractère de séparation qui a été choisi pour séparer les données

Résultat :
- Retourne une chaîne formatée contenant les données du client passé en paramètre
*/
char *clientAChaine(client *courant, char separateur){

	char chaine_tmp[MAX_CHAINE_SAISIE + 2], *chaine;
	char *nom, *prenom;
	int miles, anciennete, noordre;

	miles = courant->miles;
	anciennete = courant->anciennete;
	noordre = courant->noordre;
	nom = courant->nom;
	prenom = courant->prenom;

	sprintf(chaine_tmp, "%s%s%s%s%d%s%d%s%d", nom, separateur, prenom, separateur, miles, separateur, anciennete, separateur, noordre);

	chaine = (char *)malloc(sizeof(char)* strlen(chaine_tmp) + 1);
	strcpy(chaine, chaine_tmp);

	return chaine;

}


/*
Conversion d'une chaîne formatée à un client.
Format ici : Nom Prénom Miles Ancienneté NoOrdre. Le format sera vérifié avant que la chaine ne soit traitée par cette fonction en utilisant XXXXXXXX.

Paramètres :
- La chaine que l'on désire transeformer en client
- Le caractère de séparation qui a été choisi pour séparer les données

Résultat :
- Retourne une structure de type client selon les informations de la chaîne


*/
client ChaineAClient(char *chaine, char separateur){

	client nouveau;

	int miles = 0, anciennete = 0, noordre = 0;
	char nom_tmp[MAX_CHAINE], prenom_tmp[MAX_CHAINE], format[MAX_CHAINE];
	char *nom = NULL, *prenom = NULL;

	//Séparation de la chaîne selon le séparateur
	sprintf(format, "%s%s%s%s%d%s%d%s%d", "%s", separateur, "%s", separateur, "%d", separateur, "%d", separateur, "%d");
	sscanf(chaine, format, nom_tmp, prenom_tmp, miles, anciennete, noordre);
	
	nom = (char *)malloc(sizeof(char)* strlen(nom_tmp) + 1);
	strcpy(nom, nom_tmp);
	prenom = (char *)malloc(sizeof(char)* strlen(prenom_tmp) + 1);
	strcpy(prenom, prenom_tmp);

	nouveau.nom = nom;
	nouveau.prenom = prenom;
	nouveau.anciennete = anciennete;
	nouveau.miles = miles;
	nouveau.noordre = noordre;

	return nouveau;

}


/*
Affichage des nom et prénom d'un client

Paramètre :
- Le client dont on désire afficher le nom et le prénom

Résultat :
- Affiche à l'écran Le nom et le prénom du client (séparé d'un espace)
*/
void affNomPrenomClient(client *courant){

	printf("%s %s", courant->nom, courant->prenom);

}


/*
Saisie d'un nouveau client par saisie utilisateur

Paramètre :
- La file d'attente - Nécessaire pour l'utilisation de la fonction nbElements() qui permettra de calculer le noOrdre du client

Résultat :
- Retourne une structure de type client selon les données saisies par l'utilisateur, à savoir :
	- le nom
	- le prénom
	- Le nombre de miles
	- l'ancienneté
  l'intégrité des données est vérifié dans les fonction SaisieChaine et SaisieEntier.

*/
client saisirClient(File fileAttente){

	client nouveau;
	char *nom, *prenom;

	printf("Entrez le nom du client : ");
	nom = saisieChaine();
	suppEspace(nom);
	nouveau.nom = nom;

	printf("Entrez le prénom du client : ");
	prenom = saisieChaine();
	suppEspace(prenom);
	nouveau.prenom = prenom;


	printf("Entrez le nombre de miles du client : ");
	nouveau.miles = saisieEntier();

	printf("Entrez l'ancienneté du client : ");
	nouveau.miles = saisieEntier();

	nouveau.noordre = nbElements(fileAttente) + 1; 

	return (nouveau);

}
