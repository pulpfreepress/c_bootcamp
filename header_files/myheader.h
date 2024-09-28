#include <stdio.h>

/* Function prototypes. */
void print_message(char* message);
void print_message_n_times(char* message, int times);

void print_message(char* message){
    printf("%s\n", message);
}

void print_message_n_times(char* message, int times){
    for(int i = 0; i<times; i++){
        printf("%s\n", message);
    }
}