#include "prim.h"

void genererAcpmPrim(graphe *g, int s) {
	tas *ts = creeLP(g, s);
	cellule *tempo;
	int ind;
	sommet_file tmp;
	construireTasMin(ts);
	while (ts->taille != 0) {
		tmp = extraire_min_tas(ts);
		tempo = g->l->tabList[tmp.sommet_file]->tete;
		while (tempo != NULL) {
			ind = rechercheSommet(ts, tempo->value);
			if (tempo->poids < ts->t[ind].distance) {
				ts->t[ind].pere = tmp.sommet_file;
				DiminuerCleTas(ts, ind, tempo->poids);
			}
			tempo = tempo->succ;
		}
	}
	afficherAcpmPrim(ts);
	free(tempo);
	detruireTas(&ts);
}
