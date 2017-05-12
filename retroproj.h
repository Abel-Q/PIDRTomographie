#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

float** chargement(char * , char *);
void afficherMatice(float**, int, int);
void liberationMem(float ** , int );
