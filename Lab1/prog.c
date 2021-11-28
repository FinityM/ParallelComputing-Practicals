#include <stdio.h>

// Constant for the array size
#define arraySize 10

int main() {
    // Declare a sum,mean and the arrays values initial value
    float sum = 0;
    float mean = 0;
    float values;

    // Declare the array
    float floatArray[arraySize] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    // Print statements for the program
    printf("This program is running, it will calculate the declared arrays mean \n");
    printf("Values in the array \n");

    // The for loop to iterate through the array
    for (values = 0; values <= arraySize; values++) {

        printf("%.2f \n", values);

        // Sum up the values
        sum = sum + values;

        // Mean of the values
        mean = sum / arraySize;

    }

    printf("Mean: %.2f \n", mean);

    return 0;
}

