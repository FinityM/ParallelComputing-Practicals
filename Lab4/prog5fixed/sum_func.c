#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "functions.h"

extern int thread_count;
extern float arr[ARSIZE];
extern pthread_mutex_t mutex;
extern float sum;

void *sum_func(void *rank)
{
    float min = 1.0;
    float max = 10.0;
    long the_rank = (long) rank;
    float the_sum = 0.0;
    int local_m = ARSIZE / thread_count;     
    long first = the_rank*local_m;
    long last = first + local_m;

    printf("Sum function thread %ld of a total of %d child threads\n", the_rank, thread_count);

    for (int i = first; i < last; i++){
        the_sum += arr[ARSIZE] = ((float) rand() / (float) RAND_MAX) * (max - min) + min;
    }

    pthread_mutex_lock(&mutex);
    sum += the_sum;
    pthread_mutex_unlock(&mutex);
    
    return NULL;

}