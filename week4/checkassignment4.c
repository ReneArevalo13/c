#include <stdio.h>

// this is used for the array's size
#define SIZE 10

// this function computes the average weight
// dividing the overall weight by number of elements
double averageWeight(double arr[], int size)
{
    double totalWeight = 0;

    // computing total weight
    for(int i = 0; i < size; i++)
    {
        totalWeight += arr[i];
    }

    return totalWeight / size;
}

// this function outputs all array elements
void Show(double arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%0.3lf ", arr[i]);
    }
    printf("\n");
}

int main()
{
    double weights[SIZE] = { 57.13, 69.36, 87.64, 67.02, 85.35, 86.54, 87.10, 83.32, 49.48, 76.27};
    printf("Seals' weights: ");
    Show(weights, SIZE);

    printf("The average weight is: %0.3lf\n", averageWeight(weights, SIZE));
    return 0;
}