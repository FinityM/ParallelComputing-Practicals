void *Thread_sum(void *rank);

/* Only executed by main thread */
void Get_args(int argc, char *argv[]);
void Usage(char *prog_name);
double Serial_pi(long long n);