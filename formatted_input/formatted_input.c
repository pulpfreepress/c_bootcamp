/* Demo formatted input with scanf() */

#include <stdio.h>

int main(){

    int age = 0;

    printf("How old are you: ");
    
    scanf("%3d", &age);

    printf("You said you were %3d years old.\n", age);

    return 0;
}