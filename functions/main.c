/* Demonstrate function definitions.*/

#include <stdio.h>

/* Function prototypes. */
void print_message(char* message);
void print_message_n_times(char* message, int times);

int main(){
    print_message("Hello World!");
    print_message("I Love C Programming!");
    print_message("Don't you?");
    print_message_n_times("Hello Moto!", 5);
    return 0;
}

void print_message(char* message){
    printf("%s\n", message);
}

void print_message_n_times(char* message, int times){
    for(int i = 0; i<times; i++){
        printf("%s\n", message);
    }

}

