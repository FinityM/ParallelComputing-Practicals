void meanFunction(float *mean, float *array, int arrsize){
    float sum = 0.0;
    int i;

    for(i = 0; i < arrsize; i++){
        sum += array[i];
    }
    
    *mean =  sum / (float) arrsize;   
}

