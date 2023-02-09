#include <stdio.h>
#define MAXCHAR 1000

char* reverse(char s[]);
void copy(char to[], char from[]);


int main(){

    char line[MAXCHAR];
    int c, i;

    for (i = 0; i < (MAXCHAR - 1) && (c = getchar()) != EOF ; ++i){
        line[i] = c;
    }

    char* p = reverse(line);

    while (*p != '\0'){
        printf("%c", *p);
        p++;
    }

    printf("\n");

    return 1;
}

char* reverse(char s[]){

    char reversed[MAXCHAR];

    int i, x, len;

    len = 0;
    x = s[len];

    //get length
    while (x != '\n'){
        len = len + 1;
        x = s[len];
    }

    i = 0;

    //reverse
    while (len > 0){
        len = len - 1; 
        reversed[i] = s[len];
        ++i;
    }
    reversed[i] = '\0';

    char* p = reversed;

    return p;
}
