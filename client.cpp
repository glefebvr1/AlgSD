#include "client.h"
#include "fileattente.h"
#include "utilitaires.h"

/* Conversion client a une chaine format�e
Format ici : Nom Pr�nom Miles Anciennet� NoOrdre

Param�tre :
- Le client que l'on d�sire transform�e en cha�ne
- Le caract�re de s�paration qui a �t� choisi pour s�parer les donn�es

R�sultat :
- Retourne une cha�ne format�e contenant les donn�es du client pass� en param�tre
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
Conversion d'une cha�ne format�e � un client.
Format ici : Nom Pr�nom Miles Anciennet� NoOrdre. Le format sera v�rifi� avant que la chaine ne soit trait�e par cette fonction en utilisant XXXXXXXX.

Param�tres :
- La chaine que l'on d�sire transeformer en client
- Le caract�re de s�paration qui a �t� choisi pour s�parer les donn�es

R�sultat :
- Retourne une structure de type client selon les informations de la cha�ne


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

	return nouveau;

}


/*
Affichage des nom et pr�nom d'un client

Param�tre :
- Le client dont on d�sire afficher le nom et le pr�nom

R�sultat :
- Affiche � l'�cran Le nom et le pr�nom du client (s�par� d'un espace)
*/
void affNomPrenomClient(client *courant){

	printf("%s %s", courant->nom, courant->prenom);

}


/*
Saisie d'un nouveau client par saisie utilisateur

Param�tre :
- La file d'attente - N�cessaire pour l'utilisation de la fonction nbElements() qui permettra de calculer le noOrdre du client

R�sultat :
- Retourne une structure de type client selon les donn�es saisies par l'utilisateur, � savoir :
	- le nom
	- le pr�nom
	- Le nombre de miles
	- l'anciennet�
  l'int�grit� des donn�es est v�rifi� dans les fonction SaisieChaine et SaisieEntier.

*/
client saisirClient(File fileAttente){

	client nouveau;
	char *nom, *prenom;

	printf("Entrez le nom du client : ");
	nom = saisieChaine();
	suppEspace(nom);
	nouveau.nom = nom;

	printf("Entrez le pr�nom du client : ");
	prenom = saisieChaine();
	suppEspace(prenom);
	nouveau.prenom = prenom;


	printf("Entrez le nombre de miles du client : ");
	nouveau.miles = saisieEntier();

	printf("Entrez l'anciennet� du client : ");
	nouveau.miles = saisieEntier();

	nouveau.noordre = nbElements(fileAttente) + 1; 

	return (nouveau);

}
