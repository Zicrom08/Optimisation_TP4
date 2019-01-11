#ifndef H_KRUSKAL
#define H_KRUSKAL

#include <stdlib.h>
#include "graphe.h"
#include "ensemble.h"

void genererAcpmKruskal(graphe *);

void genererAcpmKruskalSommet(graphe *);

int estcyclehamiltonien(arete **, int);


#endif