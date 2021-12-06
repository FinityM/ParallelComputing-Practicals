/*------------------------------------------------------------------
 * Function:    Get_args
 * Purpose:     Get the command line args
 * In args:     argc, argv
 * Globals out: thread_count, n
 */

#include <stdlib.h>
#include "functions.h"

extern long long n;

extern const int MAX_THREADS;

extern long thread_count;

void Get_args(int argc, char *argv[]) {
  if (argc != 3)
    Usage(argv[0]);
  thread_count = strtol(argv[1], NULL, 10);
  if (thread_count <= 0 || thread_count > MAX_THREADS)
    Usage(argv[0]);
  n = strtoll(argv[2], NULL, 10);
  if (n <= 0)
    Usage(argv[0]);
} /* Get_args */
