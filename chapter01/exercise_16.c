#include <stdio.h>
#include <stdlib.h>

#define MAXLINE     50
#define TRUE        1
#define FALSE       0
#define INSIDE      1
#define OUTSIDE     0

int get_line(char s[], int limit);
int is_line(char s[], int limit);
int max_int(int a, int b);

int main(int argc, char **argv) {
    int len;
    int len_total = 0;
    int len_max = 0;
    int state = OUTSIDE;
    char s[MAXLINE];

    while ((len = get_line(s, MAXLINE)) > 0) {
        if (is_line(s, len)) {
            if (state = OUTSIDE) {
                len_total = len;
            } else {
                len_total += len;
            }

            len_max = max_int(len_total, len_max);
            len_total = 0;
            state = OUTSIDE;
        } else {
            state = INSIDE;
            len_total += len;
        }
    }
    
    printf("The longest line has %d characters.\n", len_max);

    return EXIT_SUCCESS;
}

int max_int(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int is_line(char s[], int len) {
    return s[len - 1] == '\n';
}

int get_line(char s[], int limit) {
    int i;
    int c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF; i++) {
        if (c == '\n') {
            s[i++] = c;
            break;
        }

        s[i] = c;
    }

    s[i] = '\0';

    return i;
}
