/*
You will a set of supporting functions using the following structure to implement a subset 
of the Python dict class in C. Some code and method signatures have been provided for you 
as well as a main() program and some support routines from the lecture slides. There is a 
good deal of discussion of this application in the lecture materials associated with this 
assignment.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode {
    char *key;
    char *value;
    struct dnode *next;
};

struct pydict {
  struct dnode *head;
  struct dnode *tail;
  int count;
};

/* Constructor - dct = dict() */
struct pydict * pydict_new() {
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(dct) */
void pydict_del(struct pydict* self) {
    struct dnode *cur, *next;
    cur = self->head;
    while(cur) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *)self);
}

/* find a node - used in get and put */
struct dnode* pydict_find(struct pydict* self, char *key)
{
    struct dnode * cur;
    for(cur = self->head; cur != NULL ; cur = cur->next ) {
        if (strcmp(cur->key, key) == 0) {
            printf("key found");
            return cur;
        }
    }
    printf("key not found");
    return NULL;
}

/* x.get(key) - Returns NULL if not found */
char* pydict_get(struct pydict* self, char *key)
{
    struct dnode * find;
    if (pydict_find(self, key)) {
        find = pydict_find(self, key);
        return find->value;
    } 
    return NULL;
    
}

/* x[key] = value; Insert or replace the value associated with a key */
void pydict_put(struct pydict* self, char *key, char *value)
{
    if (pydict_find(self, key)) {
        struct dnode * cur;
        cur = pydict_find(self, key);
        cur->value = value;
    } 
    else {
        char *save_val = (char *) malloc(strlen(value) + 1);
        strcpy(save_val, value);
        char *save_key = (char *) malloc(strlen(key) + 1);
        strcpy(save_key, key);
        struct dnode *new = (struct dnode *) malloc(sizeof(struct dnode));
        new->value = save_val;
        new->key = save_key;
        new->next = NULL;
        if (self->head == NULL) self->head = new;
        if (self->tail != NULL) self->tail->next = new;
        self->tail = new;
        self->count++;
    }
    
}

int pydict_len(const struct pydict* self)
{
    return self->count;
}

/* print(dct) */
/* {'z': 'W', 'y': 'B', 'c': 'C', 'a': 'D'} */
void pydict_print(struct pydict* self)
{
    struct dnode * cur;
    int count = 0;
    printf("{");
    for(cur = self->head; cur != NULL ; cur = cur->next ) {
        printf("'%s': '%s'", cur->key, cur->value);
        if (++count != self->count) {
            printf(", ");
        }
    }
    printf("}");
    printf("\n");
}

int main(void)
{
    struct dnode * cur;
    struct pydict * dct = pydict_new();

    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);
    pydict_put(dct, "z", "W");
    pydict_print(dct);
    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");
    pydict_print(dct);
    printf("Length =%d\n",pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");
    for(cur = dct->head; cur != NULL ; cur = cur->next ) {
        printf("%s=%s\n", cur->key, cur->value);
    }

    pydict_del(dct);
}