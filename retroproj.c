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


void afficherMatice(float** matrice,int Rx, int theta_max){
  for(int i =0;i<Rx;i++){
    for (int j =0; j<theta_max;j++){
      printf("%f\t",matrice[i][j]);
    }
    printf("\n");
  }
  printf("fin affichage\n");
}

float** chargement(char * radon, char * info){
  /*fonction permettant le chargement en memoire sous la forme d'un tableau de la transformer de Radon*/
  /*ne pas oublier de liberer la mémoire après les traitements*/
  FILE * fichier_info;
  fichier_info = fopen(info,"r");
  int Rx;
  int theta_max;
  int xp_offset;

  fscanf(fichier_info,"Rx = %d, theta_max = %d, xp_offset = %d\n",&Rx,&theta_max,&xp_offset);
  fclose(fichier_info);

  FILE * fichier_radon;
  fichier_radon = fopen(radon,"r");

  /* chargement de la matrice de la transformer de Radon dans un tableau local*/

  float R[Rx][theta_max];
  for(int i =0;i<Rx;i++){
    for (int j =0; j<theta_max;j++){
      fscanf(fichier_radon, "%f\t",&R[i][j]);
    }
    fscanf(fichier_radon,"\n");
  }

  /* creation d'un tableau alloer dynamiquement en meémoir pour pouvoir retourner la transformer de Radon*/

  float ** R_tab;
  R_tab = malloc((Rx)*sizeof(float));

  for(int u =0;u<Rx;u++){
    R_tab[u] = malloc((theta_max)*sizeof(float));
    for (int v =0; v<theta_max;v++){
      R_tab[u][v] = R[u][v];
    }
  }
  printf("chargement ok\n");
  return R_tab;
}


void liberationMem(float ** R, int Rx){ /*erreur dans les free (revoir l'allocation de mémoire, erreur dans l'allocation d'un pointeur ?)*/
  for(int i =0;i<Rx;i++){
    free(R[i]);
  }
  //free(R);
}
