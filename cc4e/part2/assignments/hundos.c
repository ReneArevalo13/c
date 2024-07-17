/*
The program will create a 10 element array and read in 10 integers into the array. Then the program 
will print the integers backwards. Then the program will scan for entries in the array which contain 
the value 100 and print out the index of the entries with the number 100. The program will also count 
the number of entries which equal 100. The program should work even if there are no entries which equal 
100.
*/

#include <stdio.h>

void backwards(int arr[], int buf[]) {
    for (int i = 0, j = 9; i < 10; i++, j--) {
        buf[i] = arr[j];
        printf("numb[%d] = %d\n", j, buf[i]);
        
    }

    // for(int i=0; i<10; i++ ) printf("numb[%d] = %d\n", i, buf[i]);
}

void hundreds(int arr[]) {
    printf("Searching for entries equal to 100\n");
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 100) {
            printf("Found 100 at %d\n", i);
            count++;
        }
    }
    printf("Found %d entries with 100", count);
}



int main() {
   int i, v, arr[10];
   int buf[10];
   for(i=0;i<10;i++) {
       scanf("%d", &v);
       arr[i] = v;
   }
//    for(i=0; i<10; i++ ) printf("Output %d\n",arr[i]);
//    for(i=0; i<10; i++ ) printf("backwards %d\n",buf[i]);
   backwards(arr, buf);
   hundreds(buf);
}