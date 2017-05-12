#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "retroproj.h"

int main(int argc, char const *argv[]) {
  float R;
  chargement("./Radon.txt","info.txt");
  //afficherMatice(R,256,180);
  return 0;
}
