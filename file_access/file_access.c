/* Demonstrate file access. */

#include <stdio.h>

int main(){

    FILE *fp = NULL;
    char *input_string = NULL;
    size_t size = 0;
    size_t characters_read;
    short keep_going = 1;

    fp = fopen("lines.txt", "a");

    while(keep_going){
        printf("Enter a line of text: ");
        characters_read = getline(&input_string, &size, stdin);
        printf("%lu\n", characters_read);
        if(characters_read > 1 ){
            if(fp){
                fputs(input_string, fp);
            }
        } else {
            keep_going = 0;
            fclose(fp);
        }
    }

    return 0;
}