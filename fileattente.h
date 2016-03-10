/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : File d'attente des clients

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************
*/

#include "client.h"
#include "listedble.h"

/* Définition de la file d'attente */
typedef idListe File;


/* Initialisation de la file d 'attente */
File *initFileAttente();


/* Destruction de la file d'attente */
void detruireFileAttente(File *fileAttente);


/* Resultat : Vrai (1) si la file est vide et Faux (0) sinon */
int fileVide(File *File);


/* Resultat : Vrai (1) si la file est pleine et Faux (0) sinon */
int filePleine(File *File);


/* Retourne le premier client */
client *premierClient(File *File);


/* Retourne le dernier client */
client *dernierClient(File *File);


/* Recherche d'un client en fonction de sa priorité : retourne le client ayant
la priorité précédant la priorité donnée ou NULL si la prioritée donnée devrait
correspondre à un client positionné avant le 1er élément
*/
client *rechercherClient(File *fileAttente, float priorite);


/* Insertion d'un nouveau client dans la file d'attente

Remarques :
- Le nouveau client doit être inséré à sa position correcte (la file est
ordonnée par priorité) => on doit rechercher la position

Ressources :
- void insereElt (idListe id, idElt courant, idElt nouveau);
- client *rechercherClient(idListe fileAttente, float priorite);
*/
void insererClient(File *fileAttente, client nvClient);


/* Suppression d'un client : supprime le client courant de la file

Ressources :
- void enleverElt (idListe id, idElt courant);
*/
void supprimerClient(File *fileAttente, client *courant);


/* chargerFile : charge une liste de clients depuis un fichier texte dans la
file d'attente

Ressources :
- client ChaineAClient(char *chaine, char separateur);
- void insererClient(idListe fileAttente, client nvClient);
*/
void chargerFile(File *fileAttente, char *cheminFichier);


/* enregistrerFile : enregistre la file d'attente dans un fichier texte

Ressources :
- char *clientAChaine(client *courant, char separateur);
- void insererClient(idListe fileAttente, client nvClient);
*/
void enregistrerFile(File *fileAttente, char *cheminFichier);
