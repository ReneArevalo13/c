#include <stdio.h>

int main(void) {

    // read in the data from the txt file
    FILE *file = fopen ("seal_data.txt", "r");
    int i = 0;
    // counter to appropriately store data in an array
    int array_counter = 0;
    int seal_data[1000];
    // use fscanf to read in the data
    fscanf (file, "%d", &i);

    // loop through the entire data file and store data in seal_data
    while (!feof (file))
    {
        seal_data[array_counter] = i;
        fscanf (file, "%d", &i);
        array_counter++;
    }
    // close the file
    fclose (file);

    // calculate the average weight via a simple for loop
    int total_weight = 0;
    double avg_weight = 0.0;

    for (int i = 0; i < 1000; i++) {
        total_weight = total_weight + seal_data[i];
    }

    avg_weight = total_weight / 1000;
    printf("The average weight of the elephant seals in this data set is: %f pounds.", avg_weight);

    return 0;
}
