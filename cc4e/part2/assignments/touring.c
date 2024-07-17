/*
This is a subset of an important concept in Computer Science called a Turing Machine. We call it a "Touring Machine" 
because it "wanders around and does things in memory" similar to a Turing Machine. Your computer has 256 characters 
of memory. The machine keeps track of the "position" or the "head" where data is to be written. The starting position 
is zero. You are to read a sequence of instructions from input and perform those instructions. When there are no more 
instructions, print the memory out as a zero-terminated C character array. Here are the instructions you need to support:

42     Store this value into the memory at the current position
>      Move the "position" one to the right (i.e. position++);
<      Move the "position" one to the left (i.e. position--);

 */

#include <stdio.h>

int main()
{
    char memory[256], token[256];
    int position = 0, value;

    while(scanf("%s",token) == 1 ) {
        printf("%s\n",token);

        //printf("%s\n",token);
        if (strcmp(token, ">") == 0) {
          position++;
          continue;
        } 
        else if (strcmp(token, "<") == 0) {
          position--;
          continue;
        } 
        else {
          value = atoi(token);
          memory[position] = value;
        }
    }
    printf("Memory:\n%s\n", memory);
}