/*You should write a function called reverse(s) that reverses the characters in a string. Reverse the string in place.*/

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

/*
Solution:
Using two pointers to reverse in place. Indices i, j indicate the position in the string. Temp is used later on for the swap.
First we need to find the index value of the end of the string, i. Increment i by 1 through a while loop until the end of the 
string is found "\0". Note to then decrement by 1 to find the index of the actual char of the string. Account for the potential edge case
of a new line and decrement by 1. Lastly perform the swap via the classic temp method and decrement the i index and increment the j index 
to move through the string.

*/