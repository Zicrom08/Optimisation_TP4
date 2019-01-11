#include <limits.h>
#include "cycle.h"

void afficherCycleHam(int *t, int n, int longueur) {
	int i;
	printf("\nLongueur : %d | ", longueur);
	for (i = 0; i < n; i++)
		printf("%d ", t[i]);
	printf("\n");
}

void permuter(int *t, int i, int j) {
	int temp = t[i];
	t[i] = t[j];
	t[j] = temp;
}

void permutationsCycles(int *t, int i, int n, int longueur, graphe *graphe,
						int *tabMin, int *min) {
	int j, fin = 0;
	if (i == n) {
		longueur += graphe->matrice[t[n - 1]][t[0]];
		afficherCycleHam(t, n, longueur);
		if (longueur < *min) {
			*min = longueur;
			for (j = 0; j < n; j++) {
				tabMin[j] = t[j];
			}
		}
	} else {
		j = i;
		while (!fin && j < n) {
			permuter(t, i, j);
			longueur += graphe->matrice[t[i - 1]][t[i]];
			permutationsCycles(t, i + 1, n, longueur, graphe, tabMin, min);
			longueur -= graphe->matrice[t[i - 1]][t[i]];
			permuter(t, i, j);
			if (t[1] == n - 1)
				fin = 1;
			j++;
		}
	}
}

int enumCyclesHam(graphe *graphe) {
	int n = graphe->nbSommet, i, longueur = 0, longueurMin = INT_MAX;
	int *tabSommets = (int *) malloc(sizeof(int) * n);
	int *tabCycleHamMin = (int *) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		tabSommets[i] = i;
		tabCycleHamMin[i] = 0;
	}
	permutationsCycles(tabSommets, 1, n, longueur, graphe, tabCycleHamMin, &longueurMin);
	printf("\nCycle hamiltonien minimum :\n");
	for (i = 0; i < n; i++)
		printf("%d ", tabCycleHamMin[i]);
	printf("\nLongueur : %d\n", longueurMin);
	free(tabSommets);
	free(tabCycleHamMin);
	return 0;
}

int contienttab(int *tab, int taille, int x) {
	for (int i = 0; i < taille; ++i) {
		if (tab[i] == x)
			return 1;
	}
	return 0;
}

int mintab(int *tab, int taille) {
	int min = INT_MAX, res = -1;
	for (int i = 0; i < taille; ++i) {
		if (tab[i] < min) {
			min = tab[i];
			res = i;
		}
	}
	return res;
}

void heuristiqueppv(graphe *graphe, int sommet) {
	cellule *tabCellule = (cellule *) malloc(sizeof(cellule) * graphe->nbSommet);
	int found = 0, res = 0;
	tabCellule[found] = *creerCellule(0, 0);
	found++;
	while (found != graphe->nbSommet) {
		tabCellule[found] = *minPoidsListe(graphe->l->tabList[tabCellule[found - 1].value], tabCellule, found);
		res += tabCellule[found].poids;
		found++;
	}
	for (int i = 0; i < graphe->nbSommet; ++i) {
		printf("%d ", tabCellule[i].value);
	}
	res += graphe->matrice[tabCellule[found - 1].value][0];
	printf("\nLongueur : %d \n", res);
}