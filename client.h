/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : Gestion des clients

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************
*/


// Descripteur de client
typedef struct client {
	char *nom;			// Nom du client
	char *prenom;		// Prénom du client
	int miles;			// Nombre de Miles parcourus
	int anciennete;		// Nombre d'années d'inscription au programme de fidélité
	int noordre;		// N° d'ordre d'arrivée (commence à 1)
	int priorite;		// Priorité du client, calculée selon la formule : miles / 1000 + anciennete - noordre
} typeClient;


/* Conversion structure client => chaîne
Format chaîne : Nom[sep]Prénom[sep]Miles[sep]Ancienneté[sep]NoOrdre
[sep] : séparateur

Paramètres :
- typeClient *courant : pointeur vers structure client
- char separateur[] : chaîne séparant chaque variable dans la chaîne formatée

Résultat :
- Valeur de retour char * : chaîne formatée contenant les données du client passé en paramètre
*/
char *clientAChaine(typeClient *courant, char separateur[]);


/* Conversion chaîne => structure client
Format chaîne : Nom[sep]Prénom[sep]Miles[sep]Ancienneté[sep]NoOrdre
[sep] : séparateur

Paramètres :
- char *chaine : chaîne formatée
- char separateur[] : chaîne séparant chaque variable dans la chaîne formatée

Résultat :
- Valeur de retour typeClient * : pointeur vers une nouvelle structure client
*/
typeClient *ChaineAClient(char *chaine, char separateur[]);


/* Affichage des nom et prénom d'un client

Paramètre :
- typeClient *courant : pointeur vers une structure client

Résultat :
- Affiche à l'écran Le nom et le prénom du client (séparé d'un espace)
*/
void affNomPrenomClient(typeClient *courant);


/* Création d'un nouveau client via saisie utilisateur

Paramètre :
- int *maxNoOrdre : pointeur vers une variable contenant le dernier n° d'ordre attribué (le plus élevé)

Résultat :
- Valeur de retour typeClient *courant : pointeur vers une nouvelle structure client

*/
typeClient *saisirClient(int *maxNoOrdre);


/* Destruction d'un client : libération de la mémoire

Paramètres :
- typeClient *cliCour : pointeur vers vers la structure client à détruire

Résultats :
- Libération de la mémoire occupée par la structure
*/
void detruireClient(typeClient *cliCour);