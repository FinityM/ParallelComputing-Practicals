#include "libVarsFunc.h"

void* halfSum(void* p){
  
  data* ptr = (data*)p;
  int n = ptr->thread_num;

  // Dynamic sum declaration for the thread join
  float* thread_sum = (float*) calloc(1, sizeof(float));

  if (n == 0){
    for(int i = 0; i < arrSize / 2; i++){
      thread_sum[0] = thread_sum[0] + ptr->arr[i];
    }
  }
  else{
    for(int i = arrSize / 2; i < arrSize; i++){
      thread_sum[0] = thread_sum[0] + ptr->arr[i];
    }
  }

  pthread_exit(thread_sum);
}
