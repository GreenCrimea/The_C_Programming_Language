#include <stdio.h>
#include <stdlib.h>

#define TABFREQ 8
#define MAXCHAR 1000

char* entab(char* s, int len);
char* insert_tab(char* s, int idx, int len);
char* remove_space(char* s, int idx, int len);


int main(){

    char line[MAXCHAR];
    int c, i, len;

    for (i = 0; i < (MAXCHAR - 1) && (c = getchar()) != EOF ; ++i){
        line[i] = c;
        len = i;
    }

    char* p = entab(line, len);

    while (*p != '\n'){
        printf("%c", *p);
        p++;
    }

    printf("\n");

    free(p);
    p = NULL;

    return 0;
}


char* entab(char* p, int len){

    int i, k, j, a, x, amount;

    a = 0;

    for (i = 0; i < len; ++i){

        if (p[i] == ' '){
            amount = i % TABFREQ;
            amount = TABFREQ - amount;

            for (j = 0; j < amount; ++j){

                if (p[i+j] != ' '){
                    a = 1;
                }

                if (j == amount && a == 0){

                    for (x = 0; x < amount; ++x){

                        p = remove_space(p, i, len);
                        len = len - (amount - 1);
                    }
                    p = insert_tab(p, i, len);
                }
            }
            a = 0;
        }
    }
    return p;
}


char* insert_tab(char* s, int idx, int len){

    char* new = malloc(MAXCHAR);
    int i;

    for (i = 0; i < idx; ++i){
        new[i] = s[i];
    }

    new[idx] = '\t';

    for (i = idx; i < len; ++i){
        new[i + 1] = s[i];
    }
    new[i] = '\0';

    return new;
}


char* remove_space(char* s, int idx, int len){

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
