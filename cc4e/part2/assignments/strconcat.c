/*
Write a C program to prompt for two strings and concatenate them as shown in in the Python code below. 
Use the functions strcpy and strcat from the string.h library in your code. Pre-allocate your character 
arrays large enought to handle up to 100 characters on input for each string (i.e. do not use malloc as we
have not yet covered that yet).

print('Enter two strings');
first = input()
second = input()
print(first + " & " + second)

 */


#include <stdio.h>
#include <string.h>
int main() {
    char s1[100];
    char s2[100];
    char concat[200];
    char middle[4] = " & ";
    printf("Enter two strings: \n");
    scanf("%s %s", s1, s2);
    strcpy(concat, s1);
    strcat(concat, middle);
    strcat(concat, s2);
    printf("%s", concat);

    return 0;
}