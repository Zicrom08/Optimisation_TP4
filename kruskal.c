#include "kruskal.h"
#include <stdlib.h>

void genererAcpmKruskal(graphe *g) {
	int i, j, k = 0;
	//construction d'un tableau de toutes les arêtes du graphe à partir de la matrice d'adjacences
	int nbArete = compteTabListe(g->l);
	arete **tab = creerArete(nbArete);
	printf("nbArete: %d\n", nbArete);
	for (i = 0; i < g->nbSommet; ++i) {
		for (j = 0; j < g->nbSommet; ++j) {
			if (g->matrice[i][j] != 0) {
				tab[k]->s1 = i;
				tab[k]->s2 = j;
				tab[k]->poids = g->matrice[i][j];
				++k;
			}
		}
	}
	//tri du tableau d'arêtes construit
	triRapide(tab, nbArete);

	//création d'une structure d'ensembles disjoints permettant de gérer les composantes
	//connexes
	ensemble **E = (ensemble **) malloc(sizeof(ensemble *) * (g->nbSommet));
	for (i = 0; i < g->nbSommet; ++i) {
		E[i] = creer_ensemble(i);
	}
	//création d'un tableau des arêtes retenues lors de l'exécution de l'algorithme
	//g->nbSommet -1 car si 12 sommets, il ne faudra que 11 arêtes
	arete **tab2 = creerArete(g->nbSommet - 1);
	k = 0;
	for (i = 0; i < nbArete; ++i) {
		if (trouver_ensemble(E[tab[i]->s1]->tete) != trouver_ensemble(E[tab[i]->s2]->tete)) {
			tab2[k] = tab[i];
			k++;
			unionE(E[tab[i]->s1]->tete, E[tab[i]->s2]->tete);
		}
	}
	afficherKruskal(tab2, g->nbSommet - 1);

	detruireArete(tab, nbArete);
	detruireArete(tab2, g->nbSommet - 1);
	detruireEnsemble(E, g->nbSommet);

}
