// Source of solution for random floats in an array http://c-for-dummies.com/blog/?p=1458
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "myfunctions.h"

#define DEBUG 0

int main(int argc, char* argv[]) {
  
  // Declare variables for the array, sum, mean, standard deviation, index, min and max
  unsigned int arraySize;
  float min;
  float max;
  float *myarray;
  float mean;
  float standDev;
  int i;

  // Call srand function to create pseudo random numbers
  srand((unsigned int) time(NULL));

  // Initialise the variables with the arguments from the terminal
  arraySize = strtol(argv[1], NULL, 10);
  min = (float) strtol(argv[2], NULL, 10);
  max = (float) strtol(argv[3], NULL, 10);

  if (min != 1 && max != 10 || arraySize <= 0){
    printf("Minimum and maximum must be between 1 and 10 and the array size cannot be 0 \n");
    exit(0);
  }

  else {
    
  // Print statements for the program
  printf("This program is running, it will calculate the declared array's mean and calculate the standard deviation \n");
  printf("Values in the array \n");

  //Give the pointer array a size
  myarray = malloc(arraySize * sizeof(float));

  // Generates random numbers between min and max, also sets the boundary
  for (i = 0; i < arraySize; i++){
    myarray[i] = ((float)rand() / (float) RAND_MAX) * (max - min) + min;

#if (DEBUG > 0) // Print the values 
    printf("%.3f \n", myarray[i]);
#endif
  }

  // Mean of the index, sum is typecasted so its the same type
  meanFunction(&mean, myarray, arraySize);
  sDeviate(&standDev, myarray, arraySize, mean);
  
  printf("Mean: %.2f \n", mean);
  printf("Standard Deviation: %.2f \n", standDev);

  free(myarray);
  
  }
  
  return 0;
}


