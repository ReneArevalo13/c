/*
You should write a function (no #include statements are needed) called htoi(str) that converts hexadecimal constant 
(base-16 0-9 and a-f) to an integer. There will not be a '0x' prefix (like in C) - just assume the input is a hex number. 
You should not use ctype.h and your code can assume the ASCII character set.
Each time you run the program, the values you need to convert 9017c (base-16) to 590204 (base-10) may be different each time you run the code.
*/

#include <stdio.h>


int htoi(char s[]) {
    int i = 0;
    int hexdigit;
    int value = 0;
    while (s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            hexdigit = s[i] - '0';
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            hexdigit = s[i] - 'a' + 10;
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            hexdigit = s[i] - 'A' + 10;
        }
        value = 16 * value + hexdigit;
        i++;
    }
    return value;
}

int main() {
    char s[] = "9017c";
   
    printf("%d", htoi(s));
  
}