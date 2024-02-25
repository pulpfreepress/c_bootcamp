/* Character Arrays | From The C Programming Language by K & R | Section 1.9 */

#include <stdio.h>

/* Symbolic Constants */
#define MAXLINE 1000

/* Function Prototypes */
int mygetline(char line[], int maxline); /* Changed name to avoid conflict with getline() in <stdio.h> on MacOS.*/
void copy(char to[], char from[]);


int main(){
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = mygetline(line, MAXLINE)) > 0){
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0){
        printf("%s", longest);
    }

    return 0;
}


/* Read a line into s, return length.*/
int mygetline(char s[], int lim){
    int c, i;

    for(i = 0; i < (lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i ){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* Copy 'from' into 'to': assume to is big enough. */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0'){
        i++;
    }
}