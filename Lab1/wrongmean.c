#include <stdio.h>

#define arraySize 10

int main()
{
    int mean = 0;
    int sum = 0;
    int i;
    int meanArray[arraySize] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (i = 0; i < arraySize; i++)
    {
        printf("%d \n", meanArray[i]);

        sum = sum + i;

        mean = sum / arraySize;
    }

    printf("Mean = %d\n", mean);

    return 0;
}

