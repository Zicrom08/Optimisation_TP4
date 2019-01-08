#ifndef TAS_H
#define TAS_H

#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

typedef struct sommet_file {
	int sommet;
	int distance;
	int pere;
} sommet_file;

typedef struct tas {
	int taille;
	int taille2; // reste fixe
	sommet_file *t;
} tas;

tas *creeLP(graphe *, int);

void swapNode(sommet_file *, int, int);

void entasserMin(tas *, int);

void construireTasMin(tas *);

int parent(int);

int droit(int);

int gauche(int);

sommet_file extraire_min_tas(tas *);

void DiminuerCleTas(tas *, int, int);

void afficherAcpmPrim(tas *);

void detruireTas(tas **);

int distancePrim(tas *);

int rechercheSommet(tas *, int);

#endif
