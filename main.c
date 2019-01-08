#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "liste.h"
#include "file.h"
#include "ensemble.h"
#include "kruskal.h"
#include "prim.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s fichier\n\n", argv[0]);
		exit(0);
	}

	graphe *g = creerGraphe(argv[1]);

	int choix = -1;
	while (choix != 0) {
		printf("TP6 - Arbres couvrants de poids minimal");
		printf("\n\n[0] Quitter\n[1] Kruskal\n[2] PRIM\nChoix: ");
		scanf("%d", &choix);
		switch (choix) {
			case 1:
				genererAcpmKruskal(g);
				break;
			case 2:
				genererAcpmPrim(g, 0);
				break;
		}
	}

	detruireGraphe(&g);
	return 0;
}
