#include <stdio.h>

#define IN  1
#define OUT 0

main() {

    int c, num_lines, num_word, num_char, state;

    state = OUT;

    num_lines = num_word = num_char = 0;

    while((c = getchar()) != EOF) {
        ++num_char;
        if (c == '\n')
            ++num_lines;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++num_word;
        }
    }
    printf("lines = %d, words = %d, chars = %d", num_lines, num_word, num_char);
}