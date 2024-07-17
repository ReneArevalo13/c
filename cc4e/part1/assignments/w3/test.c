#include<stdio.h>
#include <stdlib.h>
int main()
{
    // char string[10];
    // printf("Enter the String: ");
    // gets(string);
    // printf("\n%s",string);
    // return 0;


    // string to be converted 
    char strToConvert[] = "908475966"; 
  
    // converting string using atoi() 
    int ConvertedStr = atoi(strToConvert); 
  
    // printing the Converted String 
    printf("String to be Converted: %s\n", strToConvert); 
    printf("Converted to Integer: %d\n", ConvertedStr); 
  
    return 0; 
}