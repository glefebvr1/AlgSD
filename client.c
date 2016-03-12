#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "client.h"
#include "utilitaires.h"

/* Conversion structure client => cha�ne
Format cha�ne : Nom[sep]Pr�nom[sep]Miles[sep]Anciennet�[sep]NoOrdre
[sep] : s�parateur

Param�tres :
- typeClient *courant : pointeur vers structure client
- char separateur[] : cha�ne s�parant chaque variable dans la cha�ne format�e

R�sultat :
- Valeur de retour char * : cha�ne format�e contenant les donn�es du client pass� en param�tre
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


/* Conversion cha�ne => structure client
Format cha�ne : Nom[sep]Pr�nom[sep]Miles[sep]Anciennet�[sep]NoOrdre
[sep] : s�parateur

Param�tres :
- char *chaine : cha�ne format�e
- char separateur[] : cha�ne s�parant chaque variable dans la cha�ne format�e

R�sultat :
- Valeur de retour typeClient * : pointeur vers une nouvelle structure client
*/
typeClient *ChaineAClient(char *chaine, char separateur[]){

	typeClient *nouveau;
	int miles, anciennete, noordre, ret;
	char nom_tmp[MAX_CHAINE], prenom_tmp[MAX_CHAINE], format[MAX_CHAINE];
	char *nom = NULL, *prenom = NULL;

	//S�paration de la cha�ne selon le s�parateur
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


/* Affichage des nom et pr�nom d'un client

Param�tre :
- typeClient *courant : pointeur vers une structure client

R�sultat :
- Affiche � l'�cran Le nom et le pr�nom du client (s�par� d'un espace)
*/
void affNomPrenomClient(typeClient *courant){

	printf("\n%s %s\n\n", courant->nom, courant->prenom);

}


/* Cr�ation d'un nouveau client via saisie utilisateur

Param�tre :
- int *maxNoOrdre : pointeur vers une variable contenant le dernier n� d'ordre attribu� (le plus �lev�)

R�sultat :
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

	printf("Entrez le pr�nom du client : ");
	prenom = saisieChaine();
	suppEspace(prenom);
	nouveau->prenom = prenom;


	printf("Entrez le nombre de miles du client : ");
	nouveau->miles = saisieEntier();

	printf("Entrez l'anciennet� du client : ");
	nouveau->anciennete = saisieEntier();

	*maxNoOrdre = *maxNoOrdre + 1;
	nouveau->noordre = *maxNoOrdre;
	nouveau->priorite = nouveau->miles / 1000 + nouveau->anciennete - nouveau->noordre;

	return nouveau;
}


/* Destruction d'un client : lib�ration de la m�moire

Param�tres :
- typeClient *cliCour : pointeur vers vers la structure client � d�truire

R�sultats :
- Lib�ration de la m�moire occup�e par la structure
*/
void detruireClient(typeClient *cliCour) {
	free(cliCour->nom);
	free(cliCour->prenom);
	free(cliCour);
}