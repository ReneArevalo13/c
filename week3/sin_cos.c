//
// Created by Rene Arevalo on 4/25/24.
//

// Write a C program that has a function that prints a table of values for sine and cosine between (0, 1).
#include<stdio.h>
#include<math.h>

int main(void) {
    // define the variables to be used
    double interval, sine, cosine;
    // for loop to iterate through the values to generate values and subsequent table
    for (int i = 0; i <= 10; i++) {
        // create intervals of 0.1
        interval = i/10.0;
        sine = sin(interval);
        cosine = cos(interval);
        // print the values in a readable table format
        printf("\nSIN(%lf) = %lf \t COS(%lf) = %lf\n" , interval, sine, interval, cosine);
    }
    return 0;
}