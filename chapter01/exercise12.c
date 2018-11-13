#include <stdio.h>
#include <stdlib.h>

#define IN 1 // Inside a word.
#define OUT 0 // Outside a word.

int main(int argc, char **argv) {
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            state = IN;
            putchar(c);
        } else if (state == IN) {
            putchar('\n');
            state = OUT;
        }
    }

    return EXIT_SUCCESS;
}
