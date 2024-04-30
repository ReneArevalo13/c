//
// Created by Rene Arevalo on 4/23/24.
//
#include <stdio.h>

int main(void) {
    int miles = 26, yards = 385;
    // double kilometers;
    double kilometers = 1.609 * (miles + yards / 1760.0);
    printf("\nA marathon is %lf kilometers.\n\n", kilometers);
    return 0;
}
