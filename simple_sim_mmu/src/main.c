/*Demonstrate basic project directory structure.*/


#include "simplesim_mmu.h"

int main(int argc, char *argv[]) {

    for(int i=0; i<argc; i++){
        printf("ARG %d %s\n", i, argv[i]);
    }

    if(argc != 2){
        printf("Usage %s program_file.ssprog\n", argv[0]);
        return 1;
    }

    initialize_simulation();

    load_program(argv[1]);

    run();

    return 0;
}

