/* File: main_hello.c
// Purpose: Illustrate basic use of pthreads: create multiple threads,
// each of which prints a message.
//
// Input: none
// Output: message from each thread
//
// Usage: $./main_hello
//
// See also “Intro to Parallel Programming, Section 4.2 (p. 153 and ff.)// My firstPthreads program: create a child thread, and get it to print a message to the console
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "functions.h"

const int MAX_THREADS = 64;

/* Global variable:
   accessible to all threads. Note: we don't use the
   extern keyword here, because this file is where the global variable
   is first declared and defined.
*/

int main(int argc, char *argv[])
{
  // Initialise array size
  float arrSize = 100000.0;

  // Initialise min and max
  float min = 1.0;
  float max = 10.0;

  // Initialise an array
  float *array;

  // Initialise a mean
  float mean;

  // Initialise a sum
  float sum;

  // Randomise function
  srand((unsigned int)time(NULL));

  // Float array with random values between 1 and 10
  float *float_arr = (float *)calloc(arrSize, sizeof(float));

  for (int i = 0; i < arrSize; i++)
  {
    float_arr[i] = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
  }

  // Initialise thread to cmd args
  thread_count = atoi(argv[1]);

  // For the thread rank, use long in case of a 64-bit system.
  long thread;

  pthread_t *thread_handles; // declare array of pthread structures

  // Allocate memory for our child threads. Note: malloc creates a
  // block of memory on the heap (not the stack). So, it is essential
  // to use free() at the end of the program to free or “de-allocate”
  // the memory on the heap
  thread_handles = malloc(thread_count * sizeof(pthread_t));

  // Create the child threads, and pass the child thread rank “thread”
  // to the child_hello() function
  for (thread = 0; thread < thread_count; thread++)
    pthread_create(&thread_handles[thread], NULL, child_hello, (void *)thread);

  printf("Hello from the main thread\n");

  for (thread = 0; thread < thread_count; thread++)
    pthread_join(thread_handles[thread], NULL);

  free(thread_handles);
  return 0;
}
