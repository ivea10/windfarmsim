#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "projet.h"

float V[3][3] = {{0.04, 0.61, 0.35}, {0.11, 0.74, 0.15}, {0.2, 0.73, 0.07}};
	

int vitventjoursuivant(int vitvent) {
	float pv = (float)rand() / RAND_MAX; //Probabilité
	
	float sommeproba = 0.0;
	for (int nouvvit = 0; nouvvit<3; nouvvit++) {
		sommeproba += V[vitvent][nouvvit];
		if (pv <= sommeproba) {
			return nouvvit;
		}
	}
}

float productionjournaliere(int jinter, int T_panne[jinter+1], int vitvent, float prod[3]) {
	return prod[vitvent] * T_panne[0];
}

void pjestmaxoumin(float pj, float pM, float pm) {
	if (pj > pM) {
		pM = pj;
	}
	if (pj < pm) {
		pm = pj;
	}
}

void pannes(int jinter, int T_panne[jinter + 1], float p, int coutinter, int couttotal) {
	float ppanne;
	for (int i=0; i<T_panne[0]; i++) {
		ppanne = (float)rand() / RAND_MAX;
		if (ppanne <= p) {
			T_panne[jinter] ++;
			T_panne[0] -= 1;
			couttotal += coutinter;
		}
	}
}

void intervention(int jinter, int T_panne[jinter + 1]) {
	T_panne[0] += T_panne[1];
	for (int i=1; i<jinter; i++) {
		T_panne[i] = T_panne[i+1];
	}
	T_panne[jinter] = 0;
}	
