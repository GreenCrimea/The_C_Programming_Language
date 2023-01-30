#include <stdio.h>

main() {

    int c, num_lines, num_spaces, num_tabs;

    num_lines = 0;
    num_spaces = 0;
    num_tabs = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            ++num_lines;
        } else if(c == ' ') {
            ++num_spaces;
        } else if(c == '\t') {
            ++num_tabs;
        }
    }
    
    printf("lines = %d\nspaces = %d\ntabs = %d\n", num_lines, num_spaces, num_tabs);
}