#include "ensemble.h"

arete **creerArete(int nbSommet) {
	// cree un tableau d'arêtes
	arete **tab = (arete **) (malloc(sizeof(arete *) * (nbSommet)));
	int i;
	for (i = 0; i < nbSommet; ++i) {
		tab[i] = (arete *) (malloc(sizeof(arete)));
	}
	return tab;
}

void detruireArete(arete **t, int taille) {
	/*
  int i;
	for(i=0;i<taille;i++){
    detruireA(t[i]);
  }*/
	free(t);
	t = NULL;
}

void detruireA(arete *t) {
	free(t);
}

ensemble *creer_ensemble(int s) {
	ensemble *E = (ensemble *) (malloc(sizeof(ensemble)));
	cellS *sommet = (cellS *) (malloc(sizeof(cellS)));

	//On cree le sommet
	sommet->val = s;
	sommet->next = NULL;
	sommet->ens = E;

	E->tete = sommet;
	E->queue = sommet;
	return E;
}

void detruireEnsemble(ensemble **E, int taille) {
	/*
	cellS *tmp;
	tmp=E[0]->tete;
	while(tmp!=NULL){
	  E[0]->tete=tmp->next;
	  free(tmp);
	  tmp=tmp->next;
	}*/
	free(E);
}

//On renvoie le representant de l'ensemble
cellS *trouver_ensemble(cellS *sommet) {
	return sommet->ens->tete;
}

//union de deux ensembles
void unionE(cellS *x, cellS *y) {
	cellS *s3;
	x->ens->queue->next = y->ens->tete;
	x->ens->queue = y->ens->queue;
	for (s3 = y->ens->tete; s3 != NULL; s3 = s3->next)
		s3->ens = x->ens;
}

//triRapide triant par ordre croisant de poids
void triRapide(arete **t, int taille) {
	int sep, i;
	arete *pivot, *tmp;
	if (taille < 2) return;
	pivot = t[taille - 1];
	sep = i = 0;
	while (i < taille) {
		if (t[i]->poids <= pivot->poids) {
			if (sep != i) {
				tmp = t[i];
				t[i] = t[sep];
				t[sep] = tmp;
			}
			sep++;
		}
		i++;
	}
	triRapide(t, sep - 1);
	triRapide(t + sep - 1, taille - sep + 1);
}

//fonction calculant le poids de l'arbre sur le tas
int distanceKruskal(arete **t, int taille) {
	int i, som = 0;
	for (i = 0; i < taille; ++i) {
		som += t[i]->poids;
	}
	return som;
}

void afficherKruskal(arete **t, int taille) {
	int i;
	printf("Arbre couvrant de poids minimum : \n");
	for (i = 0; i < taille; ++i) {
		printf("%2d\t %2d\n", t[i]->s1, t[i]->s2);
	}
	printf("Longueur de l'arbre : %d\n", distanceKruskal(t, taille));
}

void afficherKruskalSommet(arete **t, int taille) {
	int i;
	printf("Arbre couvrant de poids minimum sans le sommet 0: \n");
	for (i = 0; i < taille; ++i) {
		printf("%2d\t %2d\n", t[i]->s1, t[i]->s2);
	}
	printf("Longueur de l'arbre : %d\n", distanceKruskal(t, taille));
}

void afficherAreteSommet(arete **t, int taille) {
	int i;
	printf("Arete du sommet 0: \n");
	for (i = 0; i < taille; ++i) {
		printf("%2d\t %2d\n", t[i]->s1, t[i]->s2);
	}
}
