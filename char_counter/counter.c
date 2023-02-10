#include <stdio.h>

main() {
    long num_char;

    num_char = 0;

    while(getchar() != EOF)
        ++num_char;
    
    printf("%ld\n", num_char);
}