#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int thread_count;
float arr[ARSIZE];
pthread_mutex_t mutex;
float sum;

int main(int argc, char *argv[]) {
  long thread;
  pthread_t *thread_handles;
  float mean;  

  thread_count = atoi(argv[1]);
  thread_handles = malloc(thread_count * sizeof(pthread_t));

  for (thread = 0; thread < thread_count; thread++){
      pthread_create(&thread_handles[thread], NULL, sum_func, (void*) thread);
  }

  for (thread = 0; thread < thread_count; thread++){
      pthread_join(thread_handles[thread], NULL);
  }

  mean = sum / ARSIZE;

  printf("Sum: %.2f",sum);
  printf("Mean: %.2f", mean);

  free(thread_handles);
  pthread_mutex_destroy(&mutex);

  return 0;
}