#include <math.h>
float sDeviate(float array[], int arrayS);
float sDeviate(float array[],int arrayS){
    float sum = 0;
    float mean;
    float standDev = 0;
    int i;
    for(i = 0; i < arrayS; i++){
        sum += array[i];
    }

    mean = (float) sum / arrayS;
    for (i = 0; i < arrayS; ++i){
        standDev += pow(array[i] - mean, 2);
    }
    
    return sqrt(standDev / 10);
}

