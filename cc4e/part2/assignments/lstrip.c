/*
Write a C function called py_lstrip() that removes whitespace (blanks, tabs, and newlines) from the beginning of a string. 
This function modifies its parameter and should never be called with a constant value.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void py_lstrip(char inp[]) {

    int i = 0;
    int end = strlen(inp);
    char newstring[100];

    while (inp[i] != '\0') {
        if (inp[i] == ' ' || inp[i] == '\n' || inp[i] == '\t') {
            i++;
        }
        else break;
    } 
    strncpy(newstring, inp+(i), end);
    // printf("%s\n", inp);
    // printf("%s\n", newstring);
    strcpy(inp, newstring);
    // printf("%s\n", inp);
    

}




int main() {
    char s1[] = "   Hello   World    ";
    py_lstrip(s1);
    printf("-%s-\n", s1);
}