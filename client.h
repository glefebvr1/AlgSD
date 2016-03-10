/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : Gestion des clients

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************
*/

// Descripteur du client
typedef struct {
	char *nom;
	char *prenom;
	int miles;
	int anciennete;
	int noordre;
	float priorite;
} client;


/* Conversion client -> chaine formatée, avec le séparateur fourni en paramètre
Format :
prenom,nom,miles,anciennete,noordre
*/
char *clientAChaine(client *courant, char separateur[]);


/* Conversion chaine formatée -> client, avec le séparateur fourni en paramètre
Format :
prenom,nom,miles,anciennete,noordre
*/
client ChaineAClient(char *chaine, char separateur[]);


/* Affichage des nom et prénom d'un client
*/
void affNomPrenomClient(client *courant);


/* Affichage de toutes les données d'un client
*/
void affClient(client *courant);


/* Saisie d'un nouveau client

Remarques :
- Le no d'arrivée est soit égal à 1 + dernier no d'arrivée, soit égal à 1 si
c'est le premier client => déduit du nb d'éléments dans la liste

Ressources :
- int nbElements(idListe id);
- SaisieChaine()
- SaisieEntier()
*/
client saisirClient();
