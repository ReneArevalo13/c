//
// Created by Rene Arevalo on 5/14/24.
//
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct list {
    int data;
    struct list *next;
} list;

int is_empty(const list *l) {
    return l == NULL;
}

list* create_list(int d) {
    list* head = malloc(sizeof(list));
    head -> data = d;
    head -> next = NULL;
    return head;
}

list* add_to_front(int d, list* h) {
    list* head = create_list(d);
    head -> next = h;
    return head;
}

list* array_to_list(int d[], int size) {
    list* head = create_list(d[0]);
    for (int i = 1; i < size; i++) {
        head = add_to_front(d[i], head);
    }
    return head;
}
void print_list(list* h, char* title) {
    // print five items to a line
    int new_line_counter = 5;
    printf("%s\n", title);
    while (h != NULL) {
        printf("%d, ", h -> data);
        h = h -> next;
        new_line_counter--;
        if (new_line_counter == 0) {
            printf("\n");
            new_line_counter = 5;
        }
    }
}

// fill an array with random numbers that range from {1,MAX)
void fill_random(int array[], int length, int max) {
    srand(1);
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % max + 1);
    }
}

// swap two items in array
void swap (int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
// bubble sort algorithm
void bubble_sort(int array[], int length) {

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - 1; j++) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }

}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}


int main () {
    list list_of_int;
    list* head = NULL;
    int data[100];
    fill_random(data, 100, 200);
    bubble_sort(data, 100);
    head = array_to_list(data, 100);
    print_list(head, "100 element list");
    printf("\n\n");
    return 0;
}

// test bubblesort
// int main() {
//     int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
//     //calc length
//     int n = sizeof(arr) / sizeof(arr[0]);
//     bubble_sort(arr, n);
//     printf("Sorted array: \n");
//     printArray(arr, n);
//     return 0;
// }//
// Created by Rene Arevalo on 5/14/24.
//
