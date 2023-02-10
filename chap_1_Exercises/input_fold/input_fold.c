#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define FOLDBREAK 50

char* fold_line(char* s, int len);
char* insert_break(char* s, int idx, int len);

int main(){

    char line[MAXLINE];
    int c, i, len;

    for (i = 0; i < (MAXLINE - 1) && (c = getchar()) != EOF ; ++i){
        line[i] = c;
        len = i;
    }

    char* p = fold_line(line, len);

    while (*p != '\0'){
        printf("%c", *p);
        p++;
    }

    printf("\n");

    
    p = NULL;

    return 0;
}

char* fold_line(char* p, int len){

    int i, x, a;

    a = 1;

    for (i = 0; i < len; ++i){

        x = i % FOLDBREAK;

        if (x < 15 && p[i] == ' ' && a == 0){
            p = insert_break(p, i + 1, len);
            len = len + 1;
            a = 1;
        }
        if (x == 16){
            a = 0;
        }
    }

    return p;
}

char* insert_break(char* s, int idx, int len){

    char* new = malloc(MAXLINE);
    int i;

    for (i = 0; i < idx; ++i){
        new[i] = s[i];
    }

    new[idx] = '\n';

    for (i = idx; i < len; ++i){
        new[i + 1] = s[i];
    }
    new[i + 1] = '\0';

    return new;
}