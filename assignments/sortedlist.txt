//
// Created by Rene Arevalo on 5/14/24.
//
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
typedef struct list {
    int data;
    struct list* next;
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
    // get more robust randomness with time library
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        array[i] = (rand() % max + 1);
    }
}

// swap two items in linked list
list* swap(list* ptr1, list* ptr2) {
    list* temp = ptr2 -> next;
    ptr2 -> next = ptr1;
    ptr1 -> next = temp;
    return ptr2;
}
// bubble sort algorithm
void bubble_sort(struct list** head, int count)
{
	list** h;
	int i, j, swapped;

	for (i = 0; i <= count; i++) {
		h = head;
		swapped = 0;

		for (j = 0; j < count - i - 1; j++) {
			list* p1 = *h;
			list* p2 = p1->next;

			if (p1->data > p2->data) {
				/* update the link after swapping */
				*h = swap(p1, p2);
				swapped = 1;
			}
			h = &(*h)->next;
		}
		/* break if the loop ended without any swap */
		if (swapped == 0)
			break;
	}
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

// driver code
int main () {
    list list_of_int;
    list* head = NULL;
    int data[100];
    fill_random(data, 100, 200);
    head = array_to_list(data, 100);
    print_list(head, "\nbefore sorting:");
    // int data[10];
    bubble_sort(&head, 100);
    print_list(head, "\nafter sorting:");
    printf("\n\n");
    return 0;
}

// test bubblesort
