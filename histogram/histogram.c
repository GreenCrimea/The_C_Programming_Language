#include <stdio.h>

#define IN   0
#define OUT  1

#define WORD_LEN 16

main() {

    int c, i, j, state, len;

    len = 0;
    state = OUT;

    int word_lengths[WORD_LEN];

    for (i = 0; i < 10; ++i)
        word_lengths[i] = 0;

    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            word_lengths[len]++;
            len = 0;
        } else {
            state = IN;
            len++;
        }
    }

    printf("\n----------------\nhistogram Horizontal\n----------------\n\n");

    for (i = 1; i < WORD_LEN; ++i) {
        printf("%d", i);
        for (j = 0; j < word_lengths[i]; ++j) {
            printf("=");
        }
        printf("\n");
    }

    printf("\n\n\n----------------\nhistogram Vertical\n----------------\n\n");

    int max;

    max = 0;

    for (i = 0; i < WORD_LEN; i++) {
        if (max < word_lengths[i]) {
            max = word_lengths[i];
        }
    }

    for (i = max; i != 0; i--) {
        for (j = 1; j < WORD_LEN; j++) {
            if (i <= word_lengths[j]) {
                printf(" || ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
    printf(" 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15\n");

}