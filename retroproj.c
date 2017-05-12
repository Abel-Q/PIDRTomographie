#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "retroproj.h"

/*IplImage * chargement(char * src_path){
  IplImage * img = NULL;

  if (!(img = cvLoadImage(src_path, CV_LOAD_IMAGE_GRAYSCALE))){
    printf("erreur d'ouverture de : %s\n",src_path );
    return EXIT_FAILURE;
  }
  return img;
}

IplImage * retroproj(IplImage * sinuso){
  int Rx = sinuso->width;
  int Ry = sinuso->height;
  printf("Rx = %d, Ry = %d\n",Rx,Ry );

  return sinuso;
}*/

/*int main(int argc, char const *argv[]) {
  IplImage * img =NULL;
  img = chargement("./sinusogram.jpg");
  retroproj(img);
  return 0;
}*/

/*
void afficherMatice(float matrice[256][180],int Rx, int theta_max){
  for(int i =0;i<Rx;i++){
    for (int j =0; j<theta_max;j++){
      printf("%f\t",matrice[i][j]);
    }
    printf("\n");
  }
}
*/
float chargement(char * radon, char * info){
  FILE * fichier_info;
  fichier_info = fopen(info,"r");
  int Rx;
  int theta_max;
  int xp_offset;

  fscanf(fichier_info,"Rx = %d, theta_max = %d, xp_offset = %d\n",&Rx,&theta_max,&xp_offset);
  //printf("Rx = %d, theta_max = %d, xp_offset = %d\n",Rx,theta_max,xp_offset);
  fclose(fichier_info);

  float R[Rx][theta_max];
  FILE * fichier_radon;
  fichier_radon = fopen(radon,"r");

  for(int i =0;i<Rx;i++){
    for (int j =0; j<theta_max;j++){
      fscanf(fichier_radon, "%f\t",&R[i][j]);
    }
    fscanf(fichier_radon,"\n");
  }

  return R;
}
