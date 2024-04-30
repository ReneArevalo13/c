//
// Created by Rene Arevalo on 4/25/24.
//

//Write a C program that has a function that prints a table of values for sine and cosine between (0, 1).

#include<stdio.h>
#include<math.h>

int main(void) {
    // define the variables to be used
    double interval, sine, cosine;
    int i;
    // for loop to iterate through the values to generate values and subsequent table
    for (i = 0; i < 10; i++) {
        interval = i/10.0; // will create intervals of 0.1
        sine = sin(interval);
        cosine = cos(interval);
        printf("SIN(%lf) = %lf \t COS(%lf) = %lf" , interval, sine, interval, cosine);
        return 0;
    }


}