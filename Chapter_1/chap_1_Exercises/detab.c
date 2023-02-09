#include <stdio.h>
#include <stdlib.h>

#define TABFREQ 8
#define MAXCHAR 1000

char* detab(char* s, int len);
char* insert_space(char* s, int idx, int len);
char* remove_tab(char* s, int idx, int len);


int main(){

    char line[MAXCHAR];
    int c, i, len;

    for (i = 0; i < (MAXCHAR - 1) && (c = getchar()) != EOF ; ++i){
        line[i] = c;
        len = i;
    }
    line[i - 1] = '\0';

    char* p = detab(line, len);

    while (*p != '\0'){
        printf("%c", *p);
        p++;
    }

    printf("\n");

    free(p);
    p = NULL;

    return 0;
}


char* detab(char* p, int len){

    int i, k, amount;

    for (i = 0; i < len; ++i){
        if (p[i] == '\t'){

            amount = i % TABFREQ;
            amount = TABFREQ - amount;

            p = remove_tab(p, i, len);

            for (k = 0; k < amount; ++k){
                len = len + k;
                p = insert_space(p, i + k, len);
            }
        }
    }
    return p;
}


char* insert_space(char* s, int idx, int len){

    char* new = malloc(MAXCHAR);
    int i;

    for (i = 0; i < idx; ++i){
        new[i] = s[i];
    }

    new[idx] = ' ';

    for (i = idx; i < len; ++i){
        new[i + 1] = s[i];
    }
    new[i] = '\0';

    return new;
}


char* remove_tab(char* s, int idx, int len){

    char new[MAXCHAR];
    int i;

    for (i = 0; i < idx; ++i){
        new[i] = s[i];
    }

    for (i = idx; i < len; ++i){
        new[i] = s[i + 1];
    }

    char* p = new;

    return p;
}