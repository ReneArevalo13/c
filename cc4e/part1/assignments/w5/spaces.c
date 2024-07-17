/*Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.*/

/*
But soft  what light     through yonder window breaks
It is    the east and  Juliet is the sun
Arise fair sun   and kill the envious moon
Who  is  already  sick  and  pale  with  grief
*/

#include <stdio.h>

main () {
    int c;
    char prev = 'a';
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        }
        if (c == ' ') {
            if (prev != ' ') {
                putchar(c);
            }
        }
        prev = c;
    }
}


/*
The solution here starts with initializing the current char "c" and the most recent character "prev".
The while loop goes through the input and assigns the current char to c. The first if condition checks 
whether the current char is not a space character ' '; which then puts the char to output.
The second if condition catches the case where the char is a space character, where it then checks if 
previous character was not a space character. If both these conditions are true, then "c" is sent to 
the output. Lastly, the prev variable is set to the most current char for the following iteration.
*/