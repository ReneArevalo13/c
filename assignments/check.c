#include <stdio.h>

// Function to find the maximum number in an array
int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to find the average of numbers in an array
double findAverage(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return (double)sum/n;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    FILE *output = fopen("answer-hw3.txt", "w");
    int n, i;

    // Read the size of the array from the file
    fscanf(file, "%d", &n);
    int arr[n];

    // Read the remaining integers into the array
    for (i = 0; i < n; i++)
        fscanf(file, "%d", &arr[i]);

    // Compute the average and maximum
    double avg = findAverage(arr, n);
    int max = findMax(arr, n);

    // Print the results to the screen
    printf("Average: %.2f\n", avg);
    printf("Max: %d\n", max);

    // Write the results to the output file
    fprintf(output, "Average: %.2f\n", avg);
    fprintf(output, "Max: %d\n", max);

    fclose(file);
    fclose(output);

    return 0;
}