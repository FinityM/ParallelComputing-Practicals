#include <math.h>

void sDeviate(float *stdev, float *array, int size, float mean){
  float standDev = 0.0;
  int i;
  float diff;

  for (i = 0; i < size; ++i){
    diff = array[i] - mean;
    standDev += diff * diff;
  }

  *stdev =  sqrt(standDev / size);
}

