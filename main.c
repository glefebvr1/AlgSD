/* 
***************************************************************
TITRE		: Travail Personnel AlgSD - IGL2

AUTEURS		: Bavaud François, Lefebvre Guillaume

DESCRIPTION	: Programme de gestion de surbooking pour une compagnie aérienne

DATE		: 06.03.2016

VERSION		: 1.0

***************************************************************
*/

#include <stdio.h>
#include "utilitaires.h"
#include "fileattente.h"

#ifndef CLIENTH
	#define CLIENTH
	#include "client.h"
#endif

#define FCLIENT "swissliste.txt"
#define FCLIENT_SAUVEGARDE "swisslisteSav.txt"

void main() {

	File fileAttente;
	char *fichierSource, *fichierSav;
	int choix = 0, maxNoOrdre;
	typeClient *nouveau;

	fileAttente = initFileAttente();
	fichierSource = FCLIENT;
	fichierSav = FCLIENT_SAUVEGARDE;

	// Chargement des clients dans la file, ordonnés par priorité
	// décroissante depuis un fichier texte
	maxNoOrdre = chargerFile(fileAttente, fichierSource);

	puts("1. Suppression du client le plus prioritaire (impression du nom et du prenom).");
	puts("2. Insertion d'un nouveau client.");
	puts("3. Afficher la liste des clients.");
	puts("4. Sauvegarder la liste dans le fichier swisslisteSav.txt");
	puts("");
	puts("0. Quitter le programme.");
	puts("");

	printf("Choisissez une option : ");
	choix = saisieEntier();
	while (choix != 0){
		switch (choix){
		case 1:
			// Imprime le nom et le prénom du client le plus prioritaire
			// et supprime celui-ci
			if (!fileVide(fileAttente)){
				affNomPrenomClient(premierClient(fileAttente));
				supprimerClient(fileAttente, premierClient(fileAttente));
			} else {
				puts("Il n'y a pas de client dans la file d'attente.");
			}
			break;
		case 2 :
			// Ajoute un nouveau client via la saisie utilisateur
			nouveau = saisirClient(&maxNoOrdre);
			insererClient(fileAttente, nouveau);
			break;
		case 3:
			// Affiche tous les clients de la file d'attente
			if (!fileVide(fileAttente)) {
				affFile(fileAttente);
			} else {
				puts("Il n'y a aucun client dans la file d'attente.");
			}
			
			break;
		case 4 :
			// Sauvegarde la file d'attente dans un fichier texte
			if (!fileVide(fileAttente)){
				enregistrerFile(fileAttente, fichierSav);
			} else {
				puts("La file d'attente est vide. Le fichier ne sera pas sauvegardé.");
			}
			break;
		default:
			puts("Ceci n'est pas un option disponible.");
			break;
		}

		printf("Choisissez une option : ");
		choix = saisieEntier();
	}

	// Destruction de la file
	puts("Le programme va se fermer et la file d'attente sera detruite.");
	detruireFileAttente(fileAttente);
}

