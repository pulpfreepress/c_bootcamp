/* Demo formatted input with scanf() */

#include <stdio.h>

int main(){

    int age = 0;
    char first_name[26];
    char last_name[26];
    
    printf("%s ","What's your first and last name?");
    scanf("%25s", first_name);
    scanf("%25s", last_name);
    printf("%-25s\n", first_name);
    printf("%-25s\n", last_name);

    printf("How old are you: ");
    scanf("%3d", &age);
    printf("You said you were %3d years old.\n", age);

    return 0;
}