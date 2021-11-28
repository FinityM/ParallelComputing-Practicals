// Source of solution for random floats in an array http://c-for-dummies.com/blog/?p=1458
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constant for the array size, a minimum and maximum
#define arraySize 10
#define min 20
#define max 30

float main() {
    // Call srand function to create pseudo random numbers
    srand((unsigned int) time(NULL));
    float floatArray[arraySize];

    // Declare a sum,mean and the arrays index initial value
    float sum = 0;
    float mean;
    int index;

    // Print statements for the program
    printf("This program is running, it will calculate the declared arrays mean \n");
    printf("Values in the array \n");

    // The for loop to randomise the floats,
    for (index = 0; index <= arraySize; index++) {

        //RAND_MAX Value is used to generate floating point random index
        float randval = rand() / (float) RAND_MAX;

        randval = min + randval * (max - min);

        // Populate array with the random index
        floatArray[index] = randval;

        // Print the index
        printf("%.3f \n", floatArray[index]);

        // Sum up the index
        sum += floatArray[index];
    }

    // Mean of the index, sum is typecasted so its the same type
    mean = (float) sum / arraySize;

    printf("Mean: %.2f \n", mean);

    return 0;
}
