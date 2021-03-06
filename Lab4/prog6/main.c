// Source of this program: https://www.educative.io/edpresso/how-to-sum-an-array-using-threading-in-c
// Source of global variable http://www.mathcs.emory.edu/~cheung/Courses/255/Syllabus/1-C-floatro/cprep2.html 
#define EXTERN
#include "libVarsFunc.h"

int main(void){
  arrSize = 100000;
  float min = 1.0;
  float max = 10.0;

  // Randomise function
  srand((unsigned int) time(NULL));
    
  // Declare a float array with random values between 1 and 10
  float* float_arr = (float*) calloc(arrSize, sizeof(float));
  for(int i = 0; i < arrSize; i++){
    float_arr[i] = ((float)rand() / (float) RAND_MAX) * (max - min) + min;
  }

  //Declare the arguments for 2 threads
  data thread_data[2];
  thread_data[0].thread_num = 0;
  thread_data[0].arr = float_arr;
  thread_data[1].thread_num = 1;
  thread_data[1].arr = float_arr;

  // Declare thread ids
  pthread_t tid[2];

  pthread_create(&tid[0], NULL, halfSum, &thread_data[0]);
  pthread_create(&tid[1], NULL, halfSum, &thread_data[1]);

  // Declare a space for the sum
  float* sum0;
  float* sum1;

  // Retrieve the sum
  pthread_join(tid[0], (void**)&sum0);
  pthread_join(tid[1], (void**)&sum1);

  float sum = *sum0 + *sum1;

  printf("Sum of the array: %f\n", sum);

  mean_func(&mean, arrSize, sum);

  printf("Mean of this array: %f\n", mean);

  return 0;
}


