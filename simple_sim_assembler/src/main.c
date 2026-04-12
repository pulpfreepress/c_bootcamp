#include "assembler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Usage: %s input_file.ssasm output_file.ssprog", argv[0]);
    }

    printf("Running assembler...\n");

    int memory[MAX_MEMORY] = {0};

    FILE *input_file = NULL;

    input_file = fopen(argv[1], "r");

    process_asm_file(input_file);

    fclose(input_file);


    printf("****** MAIN ***********\n");

    dump_memory();

    printf("***********************\n");


    FILE *output_file = NULL;

    output_file = fopen(argv[2], "w");

    write_machine_code_to_file(output_file);

    fclose(output_file);

    
    return 0;
}

