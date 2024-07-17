/*Write a program which prints the words in its input, one per line. A word is any string separated by a space or newline.*/

#include <stdio.h>
main () {
    int c;
    char prev = ' ';
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
        }
        if (c == ' ') {
            c = '\n';
            putchar(c);
        }
        prev = c;
    }
}

/*
Solution:
Have variables that hold both the current and previous characters, c and prev respectively.
Loop through the input string and check whether the current char is a space, which indicates the
separtion of a word. In the case where there is a space, second if condition, change the current char, c, 
to a newline char '\n'. Lastly, set the prev variable for the next iteration.
*/