/* Demonstrate Character Array Access. */

#include <stdio.h>

int main(){

    // Can modify array elements
    char name[] = "Rick";

    // Can modify name via p_name pointer
    char* p_name = name;

    

    printf("name: %s\n", name);
    printf("p_name: %s\n", p_name);

    printf("name first char: %c\n", name[0]);
    printf("p_name first char:  %c\n", p_name[0]);

    name[0] = 'S';
    p_name[0] = 'P';

    printf("name first char: %c\n", name[0]);
    printf("p_name first char:  %c\n", p_name[0]);

    return 0;
}