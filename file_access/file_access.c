/* Demonstrate file access. */

#include <stdio.h>

int main(){

    FILE *names_file = NULL;
    char line[200];
    size_t size = 200;
    size_t characters;

    names_file = fopen("names.txt", "w");
    while((characters = getline(&line, &size, stdin)) != EOF){
        if(names_file){
            fputs(characters, names_file);
        }
    }


    return 0;
}