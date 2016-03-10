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
#include "utilitaires.h"
#include "fileattente.h"


/* Initialisation de la file d 'attente */
File initFileAttente() {
	return (File)creerListe();
}


/* Destruction de la file d'attente */
void detruireFileAttente(File fileAttente) {
	detruireListe((idListe)fileAttente);
}


/* Resultat : Vrai (1) si la file est vide et Faux (0) sinon */
int fileVide(File fileAttente) {
	if (nbElements((idListe)fileAttente) == 0) {
		return true;
	}
	else {
		return false;
	}
}


/* Retourne le premier client */
client *premierClient(File fileAttente) {
	return (client *)valElt(premierElt((idListe)fileAttente));
}


/* Retourne le dernier client */
client *dernierClient(File fileAttente) {
	return (client *)valElt(dernierElt((idListe)fileAttente));
}


/* Afficher la liste, par ordre de priorité décroissante */
void AffFile(File fileAttente) {
	idElt eltCour;
	client *cliCour;

	eltCour = premierElt((idListe)fileAttente);

	while (suivantElt(eltCour) != premierElt((idListe)fileAttente)) {
		cliCour = (client *)valElt(eltCour);
		printf("%-20f%-20s%-20s%-20d%-10d%d\n", cliCour->priorite, cliCour->nom, cliCour->prenom, cliCour->miles, cliCour->anciennete, cliCour->noordre);

		eltCour = suivantElt(eltCour);
	}
}

/* Recherche d'un client en fonction de l'une de ses caractéristique
- 1 priorité : retourne l'élément dont le client a la priorité immédiatement à
	celle recherchée, ou NULL s'il n'existe aucune priorité inférieure
- 2 adresse : en fonction de l'adresse de la structure client, retourne l'élément dont
	l'adresse a été recherchée, ou NULL

sa priorité : retourne l'élément contenant le client qui a
la priorité précédant la priorité donnée ou NULL si la prioritée donnée devrait
correspondre à un client positionné avant le 1er élément
*/
idElt rechercherClient(File fileAttente, void *valeur, int type) {
	idElt eltCour, eltPrec;
	client *cliCour;
	bool trouve;

	trouve = false;
	eltCour = premierElt((idListe)fileAttente);
	eltPrec = NULL;

	while (suivantElt(eltCour) != premierElt((idListe)fileAttente) && !trouve) {
		switch (type) {
		case 1:
			cliCour = (client *)valElt(eltCour);
			if (*(float *)valeur <= cliCour->priorite) {
				trouve = true;
				eltPrec = eltCour;
			}
			break;
		case 2:
			if ((client *)valeur == (client *)valElt(eltCour)) {
				trouve = true;
				eltPrec = eltCour;
			}
			break;
		}

		eltCour = suivantElt(eltCour);
	}
	return eltPrec;
}


/* Insertion d'un nouveau client dans la file d'attente

Remarques :
- Le nouveau client doit être inséré à sa position correcte (la file est
ordonnée par priorité) => on doit rechercher la position

Ressources :
- void insereElt (idListe id, idElt courant, idElt nouveau);
- client *rechercherClient(idListe fileAttente, float priorite);
*/
void insererClient(File fileAttente, client nvClient) {
	idElt eltCour, eltNv;

	eltCour = rechercherClient((idListe)fileAttente, (void *)&(nvClient.priorite), 1);
	eltNv = creerElt((refObjet)&nvClient);
	insereElt((idListe)fileAttente, eltCour, eltNv);
}


/* Suppression d'un client : supprime le client courant de la file

Ressources :
- void enleverElt (idListe id, idElt courant);
*/
void supprimerClient(File fileAttente, client *cliCour) {
	idElt eltCour;

	eltCour = rechercherClient(fileAttente, (void *)cliCour, 2);
	enleverElt((idListe)fileAttente, eltCour);
}


/* chargerFile : charge une liste de clients depuis un fichier texte dans la
file d'attente

Ressources :
- client ChaineAClient(char *chaine, char separateur);
- void insererClient(idListe fileAttente, client nvClient);
*/
void chargerFile(File fileAttente, char *cheminFichier) {
	FILE *fichierClient;
	client cliCour;
	char ligne[MAXLIGNE], *ret;

	fichierClient = fopen(cheminFichier, "r");

	if (fichierClient != NULL) {
		ret = fgets(ligne, MAXLIGNE + 2, fichierClient);
		while (ret != NULL) {
			cliCour = ChaineAClient(ligne, SEPARATEUR);
			insererClient((idListe)fileAttente, cliCour);

			ret = fgets(ligne, MAXLIGNE, fichierClient);
		}
	}
}


/* enregistrerFile : enregistre la file d'attente dans un fichier texte

Ressources :
- char *clientAChaine(client *courant, char separateur);
- void insererClient(idListe fileAttente, client nvClient);
*/
void enregistrerFile(File fileAttente, char *cheminFichier) {
	FILE *fichierClient;
	idElt eltCour;

	fichierClient = fopen(cheminFichier, "w");

	if (fichierClient != NULL) {
		eltCour = premierElt((idListe)fileAttente);

		while (suivantElt(eltCour) != premierElt((idListe)fileAttente)) {
			fputs(clientAChaine((client *)valElt(eltCour), SEPARATEUR), fichierClient);
		}
	}
}
