/*
Write a function itob(n, s) which converts the unsigned integer n into a binary (base 2) character representation in s. 

Write itoh, which converts an integer to hexadecimal representation. You can assume that the s variable contains enough 
space. Make sure to properly terminate s with the end-of-string marker '\0' before returning.

You can use reverse(s) to reverse a string - make sure you pass a character array and not a string constant to reverse.
*/
#include <stdio.h>
void reverse(char t[]) {
    int i = 0;              // index of the string 
    int j;                  
    char temp;
    i = 0;
    while (t[i]!= '\0') {   // find the end of the entire string
        i++;
    }
    i--;                    // the index of the last char of the string
    if (t[i] == '\n') {     // handle the case where there is a newline
        i--;
    }
    j = 0;                  // set the index for the first char of the string

    while (j < i) {         // move the pointers in 
        temp = t[i];
        t[i] = t[j];
        t[j] = temp;
        i--;
        j++;
    }

}
void itob(int n, char s[]) {
    int i, val;
    for (i=0; n; i++) {
        // printf("%d", n%2);
        val = n % 2;
        s[i] = val + '0';
        n = n / 2;
        // printf("%d\n", n);
    }
    s[i++] = '\0';
    reverse(s);
    
}

void itoh(int n, char s[]) {
    int i, val;
    for (i=0; n; i++) {
        val = n % 16;
        // printf("%d\n", val);
        if (val < 10) {
            // printf("%d\n", val + '0');
            s[i] = val + '0';
        }
        else {
            s[i] = val + 'a' - 10;
        }
        n = n / 16;
    }
    s[i++] = '\0';
    reverse(s);
    
}


int main () {__XNU_PRIVATE_EXTERN
    char s[1000];
    itob(9,s);
    printf("9 in base-2 is %s\n", s);
    // itoh(42,s);
    // printf("42 in base-16 is %s\n", s);

    // itob(16,s);
    // printf("16 in base-2 is %s\n", s);
    // itoh(16,s);
    // printf("16 in base-16 is %s\n", s);

    // itob(59,s);
    // printf("59 in base-2 is %s\n", s);
    // itoh(59,s);
    // printf("59 in base-16 is %s\n", s);

    // itob(100,s);
    // printf("100 in base-2 is %s\n", s);
    // itoh(100,s);
    // printf("100 in base-16 is %s\n", s);

    // itob(254,s);
    // printf("254 in base-2 is %s\n", s);
    // itoh(254,s);
    // printf("254 in base-16 is %s\n", s);
}