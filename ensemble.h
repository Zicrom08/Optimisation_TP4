#ifndef H_ENSEMBLE
#define H_ENSEMBLE

#include <stdlib.h>
#include <stdio.h>

//structure représentant un arc
typedef struct arete {
	int s1;
	int s2;
	int poids;
} arete;

//structure cellule pour une file
//next pointe sur l'elem suivant et ens sur l'ensemble auquel  il appartient
typedef struct cellS {
	int val;// sommet
	struct cellS *next;
	struct ensemble *ens;
} cellS;

//file pour l'ensemble
typedef struct ensemble {
	struct cellS *tete;
	struct cellS *queue;
} ensemble;

arete **creerArete(int);

void detruireArete(arete **, int);

void detruireA(arete *t);

void detruireEnsemble(ensemble **, int);

ensemble *creer_ensemble(int);

cellS *trouver_ensemble(cellS *);

void unionE(cellS *, cellS *);

void triRapide(arete **, int);

int distanceKruskal(arete **, int);

void afficherKruskal(arete **, int);

#endif
