#include "kruskal.h"

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

void genererAcpmKruskalSommet(graphe *g) {
	int i, j, k = 0;
	//construction d'un tableau de toutes les arêtes du graphe à partir de la matrice d'adjacences
	int nbArete = compteTabListeSommet(g->l);
	arete **tab = creerArete(nbArete);
	for (i = 1; i < g->nbSommet; ++i) {
		for (j = 1; j < g->nbSommet; ++j) {
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
	afficherKruskalSommet(tab2, g->nbSommet - 2);

	int p, m = 0, total = 0;
	int nbArete1 = g->nbSommet - 1;
	arete **tab3 = creerArete(nbArete1);
	printf("\n");

	for (p = 1; p < g->nbSommet; ++p) {
		if (g->matrice[0][p] != 0) {
			tab3[m]->s1 = 0;
			tab3[m]->s2 = p;
			tab3[m]->poids = g->matrice[0][p];
			++m;
		}
	}
	triRapide(tab3, nbArete1);
	afficherAreteSommet(tab3, 2);

	total += tab3[0]->poids + tab3[1]->poids + distanceKruskal(tab2, g->nbSommet - 2);

	printf("Longueur total = %d\n", total);

	if (estcyclehamiltonien(tab2, nbArete1))
		printf("Ce graphe est un cycle hamiltonien \n");
	else
		printf("Ce graphe n'est pas un cycle hamiltonien \n");

	detruireArete(tab, nbArete);
	detruireArete(tab2, g->nbSommet - 1);
	detruireEnsemble(E, g->nbSommet);

}

int estcyclehamiltonien(arete **tab, int taille) {
	int *tabCount = (int *) malloc(sizeof(int) * taille);
	memset(tabCount, 0, sizeof(int) * taille);
	int res = 1;
	for (int i = 0; i < taille; ++i) {
		tabCount[tab[i]->s1]++;
		tabCount[tab[i]->s2]++;
		if (tabCount[tab[i]->s1] > 2 || tabCount[tab[i]->s2] > 2)
			res = 0;
	}
	if (tab[0]->s1 != tab[taille - 1]->s2)
		res = 0;
	free(tabCount);
	return res;
}

