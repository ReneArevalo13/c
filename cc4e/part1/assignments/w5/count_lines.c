/*Count blanks and new lines. We skip tabs because it is a little tricky.*/

#include <stdio.h>

main () {
    int c, nl, s;
    nl=0;
    s = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            nl++;
        }
        if (c == ' ') {
            s++;
        }
    }
    printf("%d %d\n", s, nl);
}