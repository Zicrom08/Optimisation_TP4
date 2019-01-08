#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "kruskal.h"
#include "prim.h"
#include "cycle.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s fichier\n\n", argv[0]);
		exit(0);
	}

	graphe *g = creerGraphe(argv[1]);

	int choix = -1;
	while (choix != 0) {
		printf("\n\n[0] Quitter\n[1] Kruskal\n[2] PRIM\n[3] MatriceAdj\n[4] ListeAdj\n[5] CycleHamil\n[6] Heuristique \nChoix: ");
		scanf("%d", &choix);
		switch (choix) {
			case 1:
				genererAcpmKruskal(g);
				break;
			case 2:
				genererAcpmPrim(g, 0);
				break;
			case 3:
				afficherMatriceAdjacences(g);
				break;
			case 4:
				afficherListeAdj(g->l);
				break;
			case 5:
				enumCyclesHam(g);
				break;
			case 6:
				heuristiqueppv(g, 0);
				break;
			default:
				break;
		}
	}

	detruireGraphe(&g);
	return 0;
}
