#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fftw3.h>

int main(void)
{
double array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//double array2[] = {1, 6, 1, 4, 5, 0, 8, 7, 8, 6, 1,0};
double *out;
double *err;
int i,size = 10;

fftw_complex *out_cpx;

fftw_plan fft;
fftw_plan ifft;
out_cpx = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*size);
out = (double *) malloc(size*sizeof(double));
err = (double *) malloc(size*sizeof(double));

fft = fftw_plan_dft_1d(size, array, out_cpx,FFTW_FORWARD, FFTW_ESTIMATE);  //Setup fftw plan for fft
ifft = fftw_plan_dft_1d(size, out_cpx, out, FFTW_BACKWARD, FFTW_ESTIMATE);   //Setup fftw plan for ifft

fftw_execute(fft);
fftw_execute(ifft);

//printf("Input:    \tOutput:    \tError:\n");
printf("Input:    \tOutput:\n");
for(i=0;i<size;i++)
{
err[i] = abs(array[i] - out[i]);
printf("%f\t%f\n",(array[i]),out[i]);
//printf("%f\t%f\t%f\n",(array[i]),out[i],err[i]);
}

fftw_destroy_plan(fft);
fftw_destroy_plan(ifft);
fftw_free(out_cpx);
free(err);
free(out);
return 0;
}
