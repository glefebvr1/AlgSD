#include "client.h"
#include "fileattente.h"
#include "utilitaires.h"

/* Conversion client a une chaine format�e, selon le s�parateur fourni en param�tre
Format : nom	prenom	miles	anciennete	noordre
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
Conversion chaine format�e � un client selon le s�parateur fourni en param�tre
Format : nom	prenom	miles	anciennete	noordre
*/
client ChaineAClient(char *chaine, char separateur){

	client nouveau;

	int miles = 0, anciennete = 0, noordre = 0;
	char nom_tmp[MAX_CHAINE], prenom_tmp[MAX_CHAINE], format[MAX_CHAINE];
	char *nom = NULL, *prenom = NULL;

	//S�paration de la cha�ne selon le s�parateur
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

	return (nouveau);

}


/*
Affichage des nom et pr�nom d'un client
*/
void affNomPrenomClient(client *courant){

	printf("%s %s", courant->nom, courant->prenom);

}


/*
Affichage de toutes les donn�es d'un client
*/
void affClient(client *courant){


	printf("%s %s %d %d %d", courant->nom, courant->prenom, courant->miles, courant->anciennete, courant->noordre);

}


/*
Saisie d'un nouveau client par saisie utilisateur

Remarques :
- Le no d'arriv�e est soit �gal � 1 + dernier no d'arriv�e, soit �gal � 1 si
c'est le premier client => d�duit du nb d'�l�ments dans la liste
*/
client saisirClient(File fileAttente){

	client nouveau;

	printf("Entrez le nom du client : ");
	nouveau.nom = saisieChaine();

	printf("Entrez le pr�nom du client : ");
	nouveau.prenom = saisieChaine();

	printf("Entrez le nombre de miles du client : ");
	nouveau.miles = saisieEntier();

	printf("Entrez l'anciennet� du client : ");
	nouveau.miles = saisieEntier();

	nouveau.noordre = nbElements(fileAttente) + 1; 

	return (nouveau);

}
