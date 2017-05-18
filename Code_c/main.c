#include <stdio.h>
#include <stdlib.h>
#include "retroproj.h"
#include <math.h>
//#include "filtre.h"
#include<time.h>


int main(int argc, char const *argv[]) {


  double** R;
  double** B;


  R = chargement("./truc2.txt","info.txt");
  //afficherMatice(R,256,180);

  B = retroprojectionDiscrete(R,"info.txt");

  ecritMatrice(B,256,"./resultat.txt");

  return 0;
}
