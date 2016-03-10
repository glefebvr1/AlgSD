/* 
***************************************************************
TITRE		: Travail Personnel AlgSD - IGL2

AUTEURS		: Bavaud François, Lefebvre Guillaume

DESCRIPTION	: Programme de gestion de surbooking pour une compagnie aérienne

DATE		: 06.03.2016

VERSION		: 1.0

***************************************************************
*/


#include "utilitaires.h"
#include "fileattente.h"

//Nom des fichier
#define FCLIENT "swissliste.txt"
#define FCLIENT_SAUVEGARDE "swisslisteSav.txt"

void main() {

	File fileAttente;
	char *cheminFichier;
	int choix = 0, i = 0;
	client nouveau, *courant;

	//creation de la file d'attente
	fileAttente = initFileAttente();


	// Chargement des clients dans la file, ordonnés par priorité
	// décroissante (en cas d'égalité, par ordre d'arrivée), depuis un
	// fichier texte
	cheminFichier = FCLIENT;
	//chargerFile(File fileAttente, char *cheminFichier);

	//Options
	puts("1. Suppression du client le plus prioritaire (impression du nom et du prenom).");
	puts("2. Insertion d'un nouveau client.");
	puts("3. Afficher la liste des clients.");
	puts("4. Sauvegarder la liste dans le fichier swissliteSav.txt");
	puts("");
	puts("0. Quitter le programme.");
	puts("");

	//Menu
	printf("Choisissez une option : ");
	choix = saisieEntier();
	while (choix != 0){
		switch (choix){
		case 1:
			// Imprime le nom et le prénom du client et supprime ce client, si la file d'attente n'est pas vide
			if (!fileVide(fileAttente)){
				affNomPrenomClient(premierClient(fileAttente));
				supprimerClient(fileAttente, premierClient(fileAttente));
			} else {
				puts("Il n'y a pas de client dans la file d'attente.");
			}
			break;
		case 2 :
			//Ajoute un client avec saisie utilisateur, si la file d'attente n'est pas pleine
			if (!filePleine(fileAttente)){
				nouveau = saisirClient(fileAttente);
				insererClient(fileAttente, nouveau);
			} else {
				puts("Impossible d'inserer un nouveau client. La file d'attente est pleine.");
			}
			break;
		case 3:
			//Affiche tous les clients de la file d'attente, si la file n'est pas vide
			if (!fileVide(fileAttente)) {
				affFile(fileAttente);
			} else {
				puts("Il n'y a aucun client dans la file d'attente.");
			}
			
			break;
		case 4 :
			// Sauvegarde la file d'attente dans un fichier .txt, si elle n'est pas vide
			if (!fileVide(fileAttente)){
				cheminFichier = FCLIENT_SAUVEGARDE;
				enregistrerFile(fileAttente, cheminFichier);
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

