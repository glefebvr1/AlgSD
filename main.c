/* 
***************************************************************
TITRE		: Travail Personnel AlgSD - IGL2

AUTEURS		: Bavaud François, Lefebvre Guillaume

DESCRIPTION	: Programme principal

DATE		: 06.03.2016

VERSION		: 1.0

1 - Analyse
Le but de ce projet est de réaliser un programme de gestion de file d'attente pour une compagnie aérienne,
qui souhaite gérer au mieux le surbooking.
Ce programme doit pouvoir générer une file d'attente des clients de la compagnie pour un vol spécifique.
Les données suivantes doivent être rentrées :
	- Nom, Prénom
	- Miles parcourus
	- Le nombre d'années d'inscription au programme de fidélité
	- Le n° d'ordre d'arrivée du client dans la file
L'algorithme suivant déterminera la priorité d'embarquement de chaque client : Miles / 1000 + fidélité - ordre

2 - Fonctionnement
Le programme charge d'abord les données listées ci-dessus depuis un fichier texte.
Il est ensuite possible de :
	- Ajouter un client supplémentaire
	- Afficher le client le plus prioritaire de la file d'attente
	- Afficher la file d'attente complète
	- Sauvegarder la file d'attente dans un autre fichier texte

2 - Choix techniques
Notre projet s'axe autour des deux choix techniques principaux suivants :
	- Considérer la librairie "listedble" comme une donnée du mandat et par conséquent qu'elle est
	  pleinement fonctionnelle et ne comporte pas d'erreur. Ainsi, en n'y apportant aucune modication,
	  nous limitons d'éventuelles erreurs supplémentaires.
	- Bien que la librairie "listedble" propose des listes doublement chaînées, nous avons décidé
	  d'utiliser des listes simplement chaînées pour la gestion de la file d'attente car nous n'en
	  avions pas le besoin et que par conséquent cela simplifie l'algorithme.

3 - Architecture
Nous avons décidé de structurer notre projet autour du type de données traité : les listes ; les files ;
les clients. Nous en sommes donc venus à diviser ce projet en 5 groupes de fichiers :
	- main.c : le programme principal
	- client.c/h : gestion des données clients, autour de la structure typeClient
	- fileattente.c/h : gestion de la file d'attente et de ses données (clients), autour du type File
	- listedble.c/h : gestion des listes, pour les données non métier
	- utilitaires.c/h : pour les fonctions diverses

Pour chacun de ces groupes, nous avons d'une part essayé de mettre en place des fonctions simples et
réutilisables, dans le but de rendre la lecture et la compréhension du code plus facile, et d'autre part
toujours dans le but de séparer les données par niveaux d'abstractions, nous avons essayé d'appliquer au
mieux le principe d'encapsulation des données.

5 - Gestion des erreurs
Finalement, nous avons décidé de gérer les erreurs suivantes :
	- Lecture et écriture de fichiers
	- Saisies utilisateur
Car, ce des données provenant d'entrées/sorties, donc des données non fiables du point de vue du
programme.

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

