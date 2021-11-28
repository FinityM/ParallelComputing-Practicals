// My first Pthreads program: create a child thread, and get it to print
// a message to the console
#include <stdio.h>
#include <pthread.h>

// Declare “Child” Thread function
void *mythread_func(void *param);

// Main driver program
int main()
{
  // Declare a handle to a pthread. This creates a unique
  // thread structure  
  pthread_t mythread_handle;
  
  // Create the thread. We won't pass any attributes or values
  // to it, so we use “NULL” in place of each of these.
  pthread_create(&mythread_handle, NULL, &mythread_func, NULL);
  
  // Get the main thread to print a message
  printf("In the main thread\n");
  
  // The pthread_join() function waits for mythread to complete
  pthread_join(mythread_handle, NULL);
  return 0;
}
