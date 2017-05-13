#include <stdio.h>
#include <stdlib.h>


double** chargement(char * , char *);
void afficherMatice(double**, int, int);
void liberationMem(double ** , int );
double** retroprojectionDiscrete(double** , char * );
void ecritMatrice(double **,int, char * );
