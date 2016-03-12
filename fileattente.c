/* 
***************************************************************
TITRE           : Travail Personnel AlgSD - IGL2

AUTEURS         : Bavaud François, Lefebvre Guillaume

DESCRIPTION     : File d'attente des clients

DATE            : 06.03.2016

VERSION         : 1.0

***************************************************************
*/


#include <stdio.h>
#include <stdlib.h>
#include "fileattente.h"
#include "utilitaires.h"


/* Initialisation d'une file d'attente

Résultat :
- Valeur de retour File : file d'attente initialisée, prête à être utilisée
*/
idListe initFileAttente() {
	return creerListe();
}


/* Destruction d'une file d'attente

Paramètres :
- File fileAttente : file d'attente qui va être détruite

Résultat :
- Libération de la mémoire occupée par la file d'attente et de tous
les clients contenus dans cette file
*/
void detruireFileAttente(idListe fileAttente) {
	idElt eltCour;

	eltCour = premierElt(fileAttente);

	// On détruit chaque client présent dans la file
	do {
		detruireClient(valElt(eltCour));
		eltCour = suivantElt(eltCour);
	} while (eltCour != premierElt(fileAttente));

	detruireListe(fileAttente);
}


/* Détermine si une file d'attente est vide

Paramètres :
- File fileAttente : file d'attente à tester

Résultat :
- Valeur de retour bool : true si la file est vide, false sinon
*/
bool fileVide(idListe fileAttente) {
	if (nbElements(fileAttente) == 0) {
		return true;
	}
	else {
		return false;
	}
}


/* Retourne le premier client d'une file d'attente

Paramètres :
- File fileAttente : file d'attente

Résultat :
- Valeur de retour typeClient * : pointeur vers le 1er client, NULL si la file est vide

*/
typeClient *premierClient(idListe fileAttente) {
	return (typeClient *)valElt(premierElt(fileAttente));
}


/* Afficher tous les clients contenus dans la file d'attente

Paramètres :
- File fileAttente : file d'attente

Résultat :
- Affiche tous les clients contenus dans la file, sans modifier l'ordre de la file
*/
void affFile(idListe fileAttente) {
	idElt eltCour;
	typeClient *cliCour;

	eltCour = premierElt(fileAttente);

	if (eltCour != NULL) {
		printf("\n%-10s%-15s%-15s%-10s%-15s%-10s\n\n", "Priorite", "Nom", "Prenom", "Miles", "Anciennete", "Ordre");

		do {
			cliCour = (typeClient *)valElt(eltCour);
			printf("%-10d%-15s%-15s%-10d%-15d%-10d\n", cliCour->priorite, cliCour->nom, cliCour->prenom, cliCour->miles, cliCour->anciennete, cliCour->noordre);
			eltCour = suivantElt(eltCour);
		} while (eltCour != premierElt(fileAttente));

		puts("");
	}
}

/* Fonction de portée privée : Recherche d'un client, en fonction d'une donnée, dans une file d'attente
Paramètres :
- idListe fileAttente : file d'attente
- void *valeur : valeur à rechercher
- int type : type de valeur à rechercher
	- type = 1 : on recherche un client en fonction de sa priorité
	- type = 2 : on recherche une structure client en fonction de son adresse (pointeur)

Résultat :
- Valeur de retour idElt : 
	- type = 1 : On renvoie l'élément d'une liste qui contient le client dont la priorité est
				 immédiatement supérieure à la priorité passée en paramètre.
				 On renvoie NULL si la priorité passée en paramètre est la plus élevée.
				 On renvoie le dernier élément si la priorité passée en paramètre est la plus basse.
	- type = 2 : On renvoie l'élément d'une liste qui contient une structure client dont l'adresse
				 (pointeur) est identique à celle passée en paramètre.
				 On renvoie NULL si aucune adresse correspondante n'est trouvée.
*/
idElt rechercherClient(idListe fileAttente, void *valeur, int type) {
	idElt eltCour, eltPrec;
	typeClient *cliCour;
	bool trouve;

	trouve = false;
	eltCour = premierElt(fileAttente);
	eltPrec = NULL;

	if (eltCour != NULL) {
		switch (type) {
		case 1: // Recherche d'une priorité
			do {
				cliCour = (typeClient *)valElt(eltCour);

				// Si la priorité recherchée est plus grande que la priorité du client courant,
				// alors on s'arrête
				if (*(int *)valeur >= cliCour->priorite) {
					trouve = true;

					if (eltCour == premierElt(fileAttente)) {
						// Si on s'est arrêté sur le 1er élément, c'est que la priorité recherchée est
						// la plus grande
						eltPrec = NULL;
					}
					else {
						// Sinon, on renvoie l'élément dont la priorité supérieure à la priorité recherchée
						eltPrec = precedentElt(eltCour);
					}
				}

				eltCour = suivantElt(eltCour);
			} while (eltCour != premierElt(fileAttente) && !trouve);

			// Si on ne s'arrête jamais, c'est que la priorité recherchée est la plus basse. On renvoie
			// donc le dernier élément
			if (!trouve) {
				eltPrec = dernierElt(fileAttente);
			}

			break;
		case 2: // recherche d'une adresse de structure client
			do {
				// si l'adresse de la structure recherchée est égale à l'adresse de la structure courante,
				// on s'arrête et on renvoie l'élément courant.
				if ((typeClient *)valeur == (typeClient *)valElt(eltCour)) {
					trouve = true;
					eltPrec = eltCour;
				}

				eltCour = suivantElt(eltCour);
			} while (eltCour != premierElt(fileAttente) && !trouve);

			break;
		}
	}
	return eltPrec;
}


/* Insertion d'un nouveau client dans la file d'attente par ordre de priorité décroissante

Paramètres :
- File fileAttente : file d'attente
- typeClient *nvClient : pointeur vers la structure client à ajouter dans la file

Résultat :
- Ajoute la structure client dans la file, en respectant un ordre de priorité décroissante.
*/
void insererClient(idListe fileAttente, typeClient *nvClient) {
	idElt eltCour, eltNv;

	if (nvClient != NULL) {
		// On recherche l'élément ayant la priorité immédiatement supérieure à celle du nouveeau client
		eltCour = rechercherClient(fileAttente, (void *)&(nvClient->priorite), 1);
		eltNv = creerElt(nvClient);
		// On insère le nouveau client juste après le client qui à la priorité immédiatement supérieure
		insereElt(fileAttente, eltCour, eltNv);
	}
}


/* Suppression d'un client

Paramètres :
- File fileAttente : file d'attente
- typeClient *courant : pointeur vers la structure client à supprimer de la file

Résultat :
- Supprime la structure client de la file et détruit cette structure et son contenu
*/
void supprimerClient(idListe fileAttente, typeClient *cliCour) {
	idElt eltCour;

	// On recherche un client dans la file en fonction de l'adresse de sa structure
	eltCour = rechercherClient(fileAttente, (void *)cliCour, 2);
	// Si on l'a trouvé, on le détruit
	if (eltCour != NULL) {
		detruireClient(valElt(eltCour));
		enleverElt(fileAttente, eltCour);
	}
}


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
int chargerFile(idListe fileAttente, char *cheminFichier) {
	FILE *fichierClient;
	typeClient *cliCour;
	char ligne[MAXLIGNE], *ret;
	int maxNoOrdre;

	maxNoOrdre = 1;
	fichierClient = fopen(cheminFichier, "r");

	if (fichierClient != NULL) {
		ret = fgets(ligne, MAXLIGNE, fichierClient);
		// Tant qu'on peut lire une ligne du fichier
		while (ret != NULL) {
			cliCour = ChaineAClient(ligne, SEPARATEUR);
			// La chaîne lue dans le fichier respecte le format
			if (cliCour != NULL) {
				insererClient(fileAttente, cliCour);

				// On incrémente le dernier n° d'ordre attribué (valeur la plus élevée)
				if (cliCour->noordre > maxNoOrdre) {
					maxNoOrdre = cliCour->noordre;
				}
			}

			ret = fgets(ligne, MAXLIGNE, fichierClient);
		}

		fclose(fichierClient);
	}

	return maxNoOrdre;
}


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
void enregistrerFile(idListe fileAttente, char *cheminFichier) {
	FILE *fichierClient;
	idElt eltCour;
	char *chClient;

	fichierClient = fopen(cheminFichier, "w");
	eltCour = premierElt(fileAttente);

	if (fichierClient != NULL && eltCour != NULL) {
		// On ajoute chaque client dans le fichier, ligne à ligne
		do {
			chClient = clientAChaine((typeClient *)valElt(eltCour), SEPARATEUR);
			fputs(chClient, fichierClient);
			free(chClient);

			eltCour = suivantElt(eltCour);
		} while (eltCour != premierElt(fileAttente));

		fclose(fichierClient);
	}
}
