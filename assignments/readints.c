/* 
Open and read a file of integers into an array that is created with the first integer telling you how many to read.
So  4  9  11  12  15  would mean create an int array size 4 and read in the remaining 4 values into data[].
Then compute their average as a double and their max  as an int.  Print all this out neatly to the screen and to 
an output file named answer-hw3. 
*/

#include<stdio.h>
#include<stdlib.h>
const int MAX_INTS = 30;

/* 
Read in integers from a file. Use the first integer to determine the size of the array. 
Fill in that array with the rest of the integers that are read in. 
*/

// read in data and store into an array
void read_data(FILE *ptr, int d[], int *size) {
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size]) == 1)
        (*size)++;
}
// print the data
void print_data(int d[], int size) {
    // printf("printing data\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t", d[i]);
        if ((i+1) % 10 == 0) printf("\n");
    }
}
// print the data to a file 
void print_data_file(int d[], int size, FILE *ofp) {
    // printf("printing data\n");
    for (int i = 0; i < size; i++) {
        fprintf(ofp, "%d\t", d[i]);
        if ((i+1) % 10 == 0) printf("\n");
    }
}
// process the data in the array to be all the elements of the original array except the first one
void process_data(int d[], int *array, int size) {
    // get the number of elements to read into array from the first element of input array
    // note the need to offset by 1
    for (int i = 1; i < size + 1; i++) {
        // printf("adding number to array:%d\n", d[i]);
        array[i-1] = d[i];
    }
}
// return the first element of read in numbers that will determine the size of array
int get_size(int d[]) {
    return d[0];
}
// get max element
int get_max(int d[], int size) {
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (max < d[i]) {
            max = d[i];
        }
    }
    return max;
}
// get the averge of the array
float get_average(int d[], int size) {
    float avg = 0.0;
    for (int i = 0; i < size; i++) {
        avg += d[i];
    }
    return avg / size;
}
// store the answer into the output file
void store_answer(int data[], int size, FILE *ifp, FILE *ofp) {
    read_data(ifp, data, &size);
    fprintf(ofp, "Original data read in from file\n");
    print_data_file(data, size, ofp);
    // process data
    int processed_size = get_size(data);
    fprintf(ofp, "\nPROCESSED DATA\n");
    fprintf(ofp, "Size of the processed array is: %d\n", processed_size);
    int processed[processed_size];
    process_data(data, processed, processed_size);
    print_data_file(processed, processed_size, ofp);
    // calculate max and average
    fprintf(ofp, "\nThe max value in the array is: %d", get_max(processed, processed_size));
    fprintf(ofp, "\nThe average value of the array is: %f\n", get_average(processed, processed_size));
}

int main(int argc, char *argv[]) {

    FILE *ifp, *ofp;
    if (argc != 2) {
        printf("Need an input file.");
        exit(1);
    }
    ifp = fopen(argv[1], "r");
    ofp = fopen("answer-hw3.txt", "w");
    int size = MAX_INTS;
    int data[MAX_INTS] = {100, 0};
    // store answer into output file
    store_answer(data, size, ifp, ofp);
    // close files
    fclose(ofp);
    fclose(ifp);
}

// EXAMPLE OF THE TEXT FILE USED WITH NAME integers.txt
/*
11 9 1 33 52 0 8 2 4 55 1 8 9 2 9 44 1 22 42 1 44 
*/