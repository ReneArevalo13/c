/*
You are to perform the following steps in a function named process(): (1) Print out the string you are passed.
(2) Count the number of characters in the string. (3) If there are more than 10 characters in the string print 
out the 9th character. (4) Go through the string and replace every blank with a dash '-' (5) Print out the new 
string with dashes.
*/

#include <stdio.h>
#include <string.h>

void process(char line[]) {
    int length = strlen(line);
    printf("String: ");
    for(int i=0; i<length; i++) printf("%c", line[i]);
    printf("\n");
    printf("Count = %d\n", length);
    if (length > 10) {
        printf("The ninth character is %c\n", line[9]);
    }
    for(int i=0; i<length; i++) {
        if (line[i] == ' ') {
            line[i] = '-';
        }
    }
    printf("String: ");
    for(int i=0; i<length; i++) printf("%c", line[i]);
    printf("\n");
    
}




int main() {
    char line[1000];
    // void process();
    strcpy(line,"Hi there and welcome to LBS290");
    process(line);
    // strcpy(line,"I love C");
    // process(line);
}