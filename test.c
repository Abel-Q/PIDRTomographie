#include <stdio.h>
#include <stdlib.h>
#include "retroproj.h"
#include <math.h>
//#include "filtre.h"
#include<time.h>


int ** tableau_test(){
  int **tab;
  tab = malloc(4*sizeof(int));
  for(int i = 0; i<4;i++){
    tab[i] = malloc(4*sizeof(int));
    for(int j = 0; j<4;j++){
      tab[i][j] = j+i;
    }
  }
  return tab;

}

void tableau_test2(int ** tab){
  for(int i = 0; i<4;i++){
    for(int j = 0; j<4;j++){
      printf("%d\t",tab[i][j]);
    }
    printf("\n");
  }
}


int main(int argc, char const *argv[]) {
  /*int ** tab;
  tab = tableau_test();
  tableau_test2(tab);*/

  float temps;
  clock_t t1, t2;

  double** R;
  double** B;


  t1 = clock();
  for(int i =0;i<10;i++){
  R = chargement("./Radon.txt","info.txt");
  //afficherMatice(R,256,180);





  int Rx, Ry;
  Rx = 256;
  Ry = 256;

  //double * img;
  //img = malloc(sizeof(double)*Rx*Ry);
  //img = miseForme(R,Rx,Ry);

  double * res_re;
  double * res_im;
  double * res;
  res = malloc(sizeof(double)*Rx*Ry);
  res_re = malloc(sizeof(double)*Rx*Ry);
  res_im = malloc(sizeof(double)*Rx*Ry);
  //transformer(R,Rx,Ry, res_re,res_im);
  /*double * reFiltre;
  double * imFiltre;
  reFiltre = malloc(sizeof(double)*Rx*Ry);
  imFiltre = malloc(sizeof(double)*Rx*Ry);

  fitreRamLak(reFiltre,imFiltre,Rx,Ry);
  filtre(res_re,res_im,reFiltre,imFiltre,Rx,Ry);*/
  //res = inverse(res_re,res_im,Rx,Ry);

  /*double ** final;

  final = miseFormeInv(res,Rx,Ry);*/


  B = retroprojectionDiscrete(R,"info.txt");
  //afficherMatice(B,256,256);

  ecritMatrice(B,256,"./resultat.txt");
}
  t2 = clock();

  temps = (float)(t2-t1)/CLOCKS_PER_SEC;
  printf("temps = %f\n",temps );




  return 0;
}
