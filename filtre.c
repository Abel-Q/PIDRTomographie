#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

int main(void)
{
double array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double array2[] = {20, 21, 22, 23, 24, 25, 26, 27, 28, 29};
double *out;
double *err;
int i,size = 10;

fftw_complex *out_cpx, *in_cpx, *result_cpx, *out_cpx2;

in_cpx = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*size);
out_cpx = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*size);
out_cpx2 = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*size);
result_cpx = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*size);
fftw_plan fft;
fftw_plan ifft;

out = (double *) malloc(size*sizeof(double));
err = (double *) malloc(size*sizeof(double));

for (i=0; i<size; i++){
  in_cpx[i][0]=array[i];
  in_cpx[i][1]=0;
}

fft = fftw_plan_dft_1d(size, in_cpx, out_cpx,FFTW_FORWARD, FFTW_ESTIMATE);  //Setup fftw plan for fft
fftw_execute(fft);
for(i=0;i<size; i++){
  out_cpx[i][0]=out_cpx[i][0]*array2[i];
}

ifft = fftw_plan_dft_1d(size, out_cpx, result_cpx, FFTW_BACKWARD, FFTW_ESTIMATE);   //Setup fftw plan for ifft

fftw_execute(ifft);

//printf("Input:    \tOutput:    \tError:\n");
printf("Input:    \tOutput:      \t Result :\n");
for(i=0;i<size;i++)
{
printf("%f\t%f+i%f\t%f+i%f\n",(array[i]),out_cpx[i][0],out_cpx[i][1],result_cpx[i][0],result_cpx[i][1]);
}


fftw_destroy_plan(fft);
fftw_destroy_plan(ifft);
fftw_free(out_cpx);
fftw_free(in_cpx);
fftw_free(result_cpx);
free(err);
free(out);
return 0;
}
