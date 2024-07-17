
// maxval = None
// minval = None
// while True:
//     line = input()
//     line = line.strip()
//     if line == "done" : break
//     ival = int(line)
//     if ( maxval is None or ival > maxval) :
//         maxval = ival
//     if ( minval is None or ival < minval) :
//         minval = ival

// print('Maximum', maxval)
// print('Minimum', minval)

// Write a C program to determine the minimum and maximum of a sequence of integer numbers on input, 
// terminated by the string "done". The patterns for input and output should match the following Python application.
// Make sure that the input lines can be at least 1000 characters. Use a middle-tested while loop, gets() and atoi() 
// to mimic the Python code below. See the lecture for guidance.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  int val, minval, maxval;
  int first = 1;
  char buffer[1000];
  char end[10] = "done";
  while(1) {
    gets(buffer);
    if (strcmp(buffer, end) == 0) break;

    val = atoi(buffer);
    if (first || val > maxval) {
        maxval = val;
    }
    if (first || val < minval) {
        minval = val;
    }
    first = 0;
  }
  printf("Maximum %d\n", maxval);
  printf("Minimum %d\n,", minval);
}