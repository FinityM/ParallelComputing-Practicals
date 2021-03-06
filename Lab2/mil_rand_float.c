// Source of solution for random floats in an array http://c-for-dummies.com/blog/?p=1458
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Constant for the array size, a minimum and maximum
#define arraySize 1000000
#define min 1
#define max 10

float meanFunction(float array[], int am);
float sDeviate(float array[], int arrayS);

float main() {
    // Call srand function to create pseudo random numbers
    srand((unsigned int) time(NULL));

    // Declare variables for the array, sum, mean, standard deviation and index
    float floatArray[arraySize];   
    float sum = 0;
    float mean;
    float standDev;
    int index;

    // Print statements for the program
    printf("This program is running, it will calculate the declared arrays mean \n");
    printf("Values in the array \n");

    // The for loop to randomise the floats,
    for (index = 0; index <= arraySize; index++) {

        //RAND_MAX Value is used to generate floating point random index
        float randval = rand() / (float) RAND_MAX;

	// Ensures that the random value has a boundary between minimum and maximum values
        randval = min + randval * (max - min);

        // Populate array with the random index
        floatArray[index] = randval;

        // Print the index
        printf("%.3f \n", floatArray[index]);

        // Sum up the index
        sum += floatArray[index];
    }

    // Mean of the index, sum is typecasted so its the same type
    mean = meanFunction(floatArray, arraySize);
    standDev = sDeviate(floatArray, arraySize);

    printf("Mean: %.2f \n", mean);
    printf("Standard Deviation: %.2f \n", standDev);

    return 0;
}

float meanFunction(float array[], int am){
    float sum = 0;
    float mean;
    int i;

    for(i = 0; i < am; i++){
        sum += array[i];
    }
    mean = (float) sum / am;

    return mean;
}

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



