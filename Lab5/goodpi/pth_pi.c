/* File:     pth_pi.c
 * Purpose:  Try to estimate pi using the formula
 *
 *              pi = 4*[1 - 1/3 + 1/5 - 1/7 + 1/9 - . . . ]
 *
 *           This version has a *very serious bug*
 *
 * Compile:  gcc -g -Wall -o pth_pi pth_pi.c -lm -lpthread
 * Run:      ./pth_pi <number of threads> <n>
 *           n is the number of terms of the series to use.
 *           n should be evenly divisible by the number of threads
 * Input:    none
 * Output:   Estimate of pi as computed by multiple threads, estimate
 *           as computed by one thread, and 4*arctan(1).
 *
 * Notes:
 *    1.  The radius of convergence for the series is only 1.  So the
 *        series converges quite slowly.
 *
 * IPP:   Section 4.4 (pp. 162 and ff.)
 */

#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

const int MAX_THREADS = 1024;

long thread_count;
long long n;
double sum;

int main(int argc, char *argv[]) {
  long thread; /* Use long in case of a 64-bit system */
  pthread_t *thread_handles;

  /* Get number of threads from command line */
  Get_args(argc, argv);

  thread_handles = (pthread_t *)malloc(thread_count * sizeof(pthread_t));
  sum = 0.0;

  for (thread = 0; thread < thread_count; thread++)
    pthread_create(&thread_handles[thread], NULL, Thread_sum, (void *)thread);

  for (thread = 0; thread < thread_count; thread++)
    pthread_join(thread_handles[thread], NULL);

  sum = 4.0 * sum;
  printf("With n = %lld terms,\n", n);
  printf("   Our estimate of pi = %.15f\n", sum);
  sum = Serial_pi(n);
  printf("   Single thread est  = %.15f\n", sum);
  printf("                   pi = %.15f\n", 4.0 * atan(1.0));

  free(thread_handles);
  return 0;
} /* main */
