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


void main() {

	// Création d'une file d'attente
	// File *initFileAttente();

	// Chargement des clients dans la file, ordonnés par priorité
	// décroissante (en cas d'égalité, par ordre d'arrivée), depuis un
	// fichier texte
	// void chargerClients(File *fileAttente, char *cheminFichier);

	// Menu
		// 1 - Suppression du client le plus prioritaire, avec
		// impression nom + prénom
		// Afficher nom + prénom
		// void affNomPrenomClient(client *courant);
		// void supprimerClient(File fileAttente, client *courant);

		// 2 - Insertion nouveau client avec incrémentation ordre
		// arrivée, ou 1 si premier
		// client saisirClient();
		// void insererClient(File fileAttente, client nvClient);

		// 3 - Afficher le contenu de la file (en mémoire)
		// void affClient(client *courant);

		// 4 - Enregistrer la file dans un nouveau fichier texte,
		// les clients étant ordonnés par ordre d'arrivée
		// void enregistrerClients(File *fileAttente, char *cheminFichier);

		// 0 - Fin du programme

	// Destruction de la file
	// void detruireFileAttente(File *fileAttente);
}
