/* Demonstrates stack vs. heap memory. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void function_a(void);
void function_b(void);

int main(){
    char name[] = "main()";
    printf("%s function called...\n", name);
    int a = 1;
    function_a();
    return 0;
}

void function_a(){
    char name[] = "function_a()";
    printf("%s function called...\n", name);
    int b = 2;
    function_b();
}

void function_b(){
    char* name = malloc(sizeof(char) * 25);
    if (name){
        strcpy(name, "function_b()\0" );
        name[0] = 'F';
        printf("%s function called...\n", name);
        free(name);
    }else{
        printf("Memory allocation failed!\n");
    }
}
