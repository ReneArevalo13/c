//
// Created by Rene Arevalo on 4/23/24.
//
#include <stdio.h>

int main(void) {
    int yards = 0;
    int miles;
    // double kilometers;
    printf("Please enter distance in miles as an integer:");
    scanf("%d", &miles);
    double kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\n %d miles is %lf kilometers.\n\n", miles, kilometers);
    return 0;
}