#include <stdio.h>

int vitventjoursuivant(int vitvent);
float productionjournaliere(int jinter, int T_panne[jinter+1], int vitvent, float prod[3]);
void pjestmaxoumin(float pj, float pM, float pm);
void pannes(int jinter, int T_panne[jinter+1], float p, int coutinter, int couttotal);
void intervention(int jinter, int T_panne[jinter+1]);
