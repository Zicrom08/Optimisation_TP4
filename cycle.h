#ifndef _CYCLE_H
#define _CYCLE_H

#include "graphe.h"

void afficherCycleHam(int *, int, int);

void permuter(int *, int, int);

void permutationsCycles(int *, int, int, int, graphe *,
						int *, int *);

int enumCyclesHam(graphe *);

int contienttab(int *, int, int);

int mintab(int *, int);

void heuristiqueppv(graphe *, int);

#endif
