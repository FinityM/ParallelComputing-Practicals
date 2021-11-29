// Header file that includes all of the libraries, variables and functions
#ifndef EXTERN
#define EXTERN extern   
#endif

EXTERN int arrSize;
EXTERN float mean;

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct data{
  float* arr;
  int thread_num;
} data;

void* halfSum(void* p);
void mean_func(float *mean, int arrSize, float sum);
