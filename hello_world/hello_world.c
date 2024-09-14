/* ***********************************************
 * Project: hello_world.c
 * 
 * Everyone's first C program.
 * 
*********************************************** */



#include <stdio.h>

int main(){ 
    char* message_1 = "Hello";
    char* message_2 = "World!";
    char c = 'A';

    printf("Hello World!\n");
    printf("Hello World!\n");
    printf("Value printed is: %s\n", "Hello World");
    printf("%s %s\n", message_1, message_2);
    printf("%15s %15s\n", message_1, message_2);
    printf("%-15s %-15s\n", message_1, message_2);
    printf("%-3s %-3s\n", message_1, message_2);
    printf("%-3c\n", c);
    
}