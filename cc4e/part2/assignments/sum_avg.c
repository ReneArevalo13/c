/*
This program will prompt for 5 floating point numbers. The program will print out the total of the five 
numbers and also print out the average.
*/

#include <stdio.h>

int main () {
    float num0, num1, num2, num3, num4;
    printf("enter 5 floating point numbers\n");
    scanf("%f %f %f %f %f", &num0, &num1, &num2, &num3, &num4);
    printf("Inputted values are: %f %f %f %f %f\n", num0, num1, num2, num3, num4);
    float sum = num0 + num1 + num2 + num3 + num4;
    float avg = (sum) / 5.0;

    printf("The sum is: %.1f\n", sum);
    printf("The average is: %.1f\n", avg);
    return 0;
}