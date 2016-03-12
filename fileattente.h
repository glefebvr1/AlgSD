/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : File d'attente des clients

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************
*/

#include "listedble.h"

#ifndef CLIENTH
	#define CLIENTH
	#include "client.h"
#endif

#define MAXLIGNE 255
#define SEPARATEUR "\t"


/* Définition d'une file d'attente
La file d'attente est une liste de type idListe
*/
typedef idListe File;


/* Initialisation d'une file d'attente

Résultat :
- Valeur de retour File : file d'attente initialisée, prête à être utilisée
*/
File initFileAttente();


/* Destruction d'une file d'attente

Paramètres :
- File fileAttente : file d'attente qui va être détruite

Résultat :
- Libération de la mémoire occupée par la file d'attente et de tous
les clients contenus dans cette file
*/
void detruireFileAttente(File fileAttente);


/* Détermine si une file d'attente est vide

Paramètres :
- File fileAttente : file d'attente à tester

Résultat :
- Valeur de retour bool : true si la file est vide, false sinon
*/
bool fileVide(File fileAttente);


/* Retourne le premier client d'une file d'attente

Paramètres :
- File fileAttente : file d'attente

Résultat :
- Valeur de retour typeClient * : pointeur vers le 1er client, NULL si la file est vide

*/
typeClient *premierClient(File fileAttente);


/* Afficher tous les clients contenus dans la file d'attente

Paramètres :
- File fileAttente : file d'attente

Résultat :
- Affiche tous les clients contenus dans la file, sans modifier l'ordre de la file
*/
void affFile(File fileAttente);


/* Insertion d'un nouveau client dans la file d'attente par ordre de priorité décroissante

Paramètres :
- File fileAttente : file d'attente
- typeClient *nvClient : pointeur vers la structure client à ajouter dans la file

Résultat :
- Ajoute la structure client dans la file, en respectant un ordre de priorité décroissante.
*/
void insererClient(File fileAttente, typeClient *nvClient);


/* Suppression d'un client

Paramètres :
- File fileAttente : file d'attente
- typeClient *courant : pointeur vers la structure client à supprimer de la file

Résultat :
- Supprime la structure client de la file et détruit cette structure et son contenu
*/
void supprimerClient(File fileAttente, typeClient *courant);


/* Charge une liste de clients depuis un fichier texte vers une file d'attente
Format du fichier :
- Un client par ligne
- format de la ligne : Nom[sep]Prénom[sep]Miles[sep]Ancienneté[sep]NoOrdre
- [sep] : séparateur

Paramètres :
- File fileAttente : file d'attente
- char *cheminFichier : chaîne contenant le chemin du fichier à charger

Résultat :
- Ajoute chaque client présent dans le fichier dans la file d'attente, en
respectant un ordre de priorité décroissante.
- Valeur de retour int : dernier n° d'ordre attribué (valeur la plus élevée)
*/
int chargerFile(File fileAttente, char *cheminFichier);


/* Enregistre une file d'attente dans un fichier texte
Format du fichier :
- Un client par ligne
- format de la ligne : Nom[sep]Prénom[sep]Miles[sep]Ancienneté[sep]NoOrdre
- [sep] : séparateur

Paramètres :
- File fileAttente : file d'attente
- char *cheminFichier : chaîne contenant le chemin du fichier à enregistrer

Résultat :
- Enregistre chaque client présent dans la file d'attente dans un fichier texte
*/
void enregistrerFile(File fileAttente, char *cheminFichier);
