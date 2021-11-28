// The mythread_func() function is the code of the child thread.
// It simply prints a message to the console.
#include <stdio.h>
#include <stdlib.h>

/* Need to tell the compiler that thread_count has been declared
   Page 13 of 15// externally to the child_hello.c file (because it was declared
   in main_hello.c)
*/
extern int thread_count;

void *child_hello(void *rank)
{
  long my_rank = (long) rank;
  /* Use long in case of 64-bit system */
  printf("Hello from child thread %ld of a total of %d child threads\n",my_rank, thread_count);
}
