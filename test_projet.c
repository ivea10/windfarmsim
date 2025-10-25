#include <stdio.h>
#include "projet.h"

int J;
int N; //Nombre d'éoliennes fonctionnelles
float pt = 0; //Production totale en MW
float pj; //Production journaliere en MW
float pM = 0; //Production journaliere maximale en MW
float pm; //Production journaliere minimale en MW
float fv; //Force du vent
int vitvent; //Correspond à la vitesse du vent : 0 pour nulle, 1 pour moyenne et 2 pour forte
int coutinter; //Coût d'intervention (en milliers d'euros)
int couttotal;
int jinter; //Nombre de jours d'intervention
int C;

float prod[3] = {0, 0.4, 0.65};
float p = 0.15;

int main(void) {
	printf("Nombre de jours : ");
	scanf("%d", &J);
	
	printf("Taille du parc (en nombre d'éoliennes) : ");
	scanf("%d", &N);
	
	printf("Probabilite pour une eolienne de tomber en panne (entre 0 et 1) : ");
	scanf("%f", &p);
	
	printf("Cout d'une intervention (en milliers d'euros) : ");
	scanf("%d", &coutinter);
	
	printf("Duree d'une intervention (en jours) : ");
	scanf("%d", &jinter);
	int T_panne[jinter + 1]; //Tableau comptant le nombre d'éoliennes dont il reste 1,2,...,jinter jours d'intervention. Par exemple, si 5 est en position 0 du tableau, alors 5 éoliennes ont 1 jour d'intervention restant
	
	printf("La production journaliere du jour 1 est de 0.0 MW \n");
	for (int i=0; i<jinter+1; i++) {
		T_panne[i] = 0;
	}
	T_panne[0] = N;
	
	for (int j=2; j<=J; j++) { //On commence au jour 2 car la vitesse du vent au jour 1 est nulle
		
		vitvent = vitventjoursuivant(vitvent);
		
		pj = productionjournaliere(jinter, T_panne, vitvent, prod);
		printf("La production journaliere du jour %d est de %.2f MW \n", j, pj);
		pt += pj; 
		
		pjestmaxoumin(pj, pM, pm);
		
		if (vitvent == 2) {
			pannes(jinter, T_panne, p, coutinter, couttotal);
		}
		else if (vitvent == 0 || vitvent == 1) {
			intervention(jinter, T_panne);
		}		
	}
	
	printf("Le parc d'éoliennes a produit au total %.2f MW \n", pt);
	printf("La production journaliere maximale est de %.2f MW \n", pM);	
	printf("Le cout total d'intervention est de %d milliers d'euros \n", couttotal); 
	
	
	return 0;
}
	
