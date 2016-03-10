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


/* Conversion client a une chaine formatée
Format ici : Nom Prénom Miles Ancienneté NoOrdre

Paramètres :
- Le client que l'on désire transformée en chaîne
- Le caractère de séparation qui a été choisi pour séparer les données

Résultat :
- Retourne une chaîne formatée contenant les données du client passé en paramètre
*/
char *clientAChaine(client *courant, char separateur);


/*
Conversion d'une chaîne formatée à un client.
Format ici : Nom Prénom Miles Ancienneté NoOrdre. Le format sera vérifié avant que la chaine ne soit traitée par cette fonction en utilisant XXXXXXXX.

Paramètres :
- La chaine que l'on désire transeformer en client
- Le caractère de séparation qui a été choisi pour séparer les données

Résultat :
- Retourne une structure de type client selon les informations de la chaîne


*/
client ChaineAClient(char *chaine, char separateur);



/*
Affichage des nom et prénom d'un client

Paramètre :
- Le client dont on désire afficher le nom et le prénom

Résultat :
- Affiche à l'écran Le nom et le prénom du client (séparé d'un espace)
*/
void affNomPrenomClient(client *courant);


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
client saisirClient(File fileAttente);
