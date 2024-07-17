/*
You should write a function (no #include statements are needed) called lower(c) that converts its input parameter to lower case. 
If the letter is not an upper case ASCII letter - just return the parameter unchanged. You should not use ctype.h and your code 
can assume the ASCII character set. You should use the question mark (?) operator and not an if-then-else construct.

Each time you run the program, the values you need to convert may be different. The main program will be provided.
*/


int lower(int c) {

    c = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
    return c;
}