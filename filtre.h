#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

void transformer(double * , int , int , double *, double * );
double* inverse(double * , double * , int , int);
void filtre(double* ,double*, double *,double * , int, int);
void fitreRamLak(double *, double *, int, int);
double * miseForme(double ** , int , int );
