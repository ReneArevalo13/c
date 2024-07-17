/*
You will a set of supporting functions using the following structures to implement a subset of the Python list class in C. 
Some code and method signatures have been provided for you as well as a main() program and some support routines from the 
lecture slides. There is a good deal of discussion of this application in the lecture materials associated with this assignment.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *text;
    struct lnode *next;
};

struct pylist {
  struct lnode *head;
  struct lnode *tail;
  int count;
};

/* Constructor - lst = list() */
struct pylist * pylist_new() {
    struct pylist *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(lst) */
void pylist_del(struct pylist* self) {
    struct lnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

/* print(lst) */
void pylist_print(struct pylist* self)
{
    /* About 10 lines of code 
       The output should match Python's
       list output

       ['Hello world', 'Catch phrase']

	Use printf cleverly, *not* string
	concatenation since this is C, not Python.
    */ 
   struct lnode *current;
   int count = 0;
   printf("[");
   for (current = self->head; current != NULL; current = current->next ) {
        printf("'");
        printf("%s", current->text);
        printf("'");
        if (++count != self->count){
            printf(", ");
    }
    
   }
   printf("]");
   printf("\n");
}

void pylist_append(struct pylist* self, char *str) {
    /* Review: Chapter 6 lectures and assignments */
    // string allocation
    char *save = (char *) malloc(strlen(str) + 1);
    strcpy(save, str);
    // create the node to be inserted
    struct lnode *new = (struct lnode *) malloc(sizeof(struct lnode));
    new->text = save;
    new->next = NULL;

    if (self->head == NULL) self->head = new;
    if (self->tail != NULL) self->tail->next = new;
    self->tail = new;
    self->count++;
}
int pylist_index(struct pylist* self, char *str)
{
    /* Seven or so lines of code */
    struct lnode *current;
    int count = 0;
    for (current = self->head; current != NULL; current = current->next ) {
        if (strcmp(str, current->text) == 0) {
            return count;
        }
        count++;
    }   
    return -1;
}


int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    struct pylist * lst = pylist_new();
    pylist_append(lst, "Hello world");
    pylist_print(lst);
    pylist_append(lst, "Catch phrase");
    pylist_print(lst);
    pylist_append(lst, "Brian");
    pylist_print(lst);
    printf("Length = %d\n", pylist_len(lst));
    printf("Brian? %d\n", pylist_index(lst, "Brian"));
    printf("Bob? %d\n", pylist_index(lst, "Bob"));
    pylist_del(lst);
}