#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "retroproj.h"


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

  float** R;
  R = chargement("./Radon.txt","info.txt");
  afficherMatice(R,256,180);
  


  return 0;
}
