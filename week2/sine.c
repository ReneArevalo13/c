//
// Created by Rene Arevalo on 4/24/24
//

/* Write a program that prints the sine function for an input x between [0,1) */

#include <stdio.h>
#include <math.h>


int main(void) {
    double x;
    printf("Please enter a value of X between 0 and 1\n");
    scanf("%lf", &x);
    double value_of_sine = sin(x);
    printf("The sine value of %lf is: %lf", x, value_of_sine);
    return 0;
}