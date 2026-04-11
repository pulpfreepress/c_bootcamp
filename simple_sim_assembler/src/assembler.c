
#include "assembler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


Symbol symbol_table[MAX_MEMORY];
int symbol_count = 0;


int get_opcode(const char *op){
    if (!strcmp(op, "READ")) return READ;
    if (!strcmp(op, "WRITE")) return WRITE;
    if (!strcmp(op, "LOAD")) return LOAD;
    if (!strcmp(op, "STORE")) return STORE;
    if (!strcmp(op, "ADD")) return ADD;
    if (!strcmp(op, "SUB")) return SUB;
    if (!strcmp(op, "MUL")) return MUL;
    if (!strcmp(op, "DIV")) return DIV;
    if (!strcmp(op, "JMP")) return JMP;
    if (!strcmp(op, "JMPN")) return JMPN;
    if (!strcmp(op, "JMPZ")) return JMPZ;
    if (!strcmp(op, "HALT")) return HALT;
    return 0;
}


void add_symbol(const char *label, int address) {
    strcpy(symbol_table[symbol_count].label, label);
    symbol_table[symbol_count].address = address;
    symbol_count++;
}


void process_asm_file(FILE *fp, int *memory){
    char line[100];
    int loc = 0;

    while(fgets(line, sizeof(line), fp)){
        char op[7] = {"0"};
        int operand = 0;

        sscanf(line, "%s %d", op, &operand);
        memory[loc] = ((get_opcode(op) * 100) + operand);
        //printf("%i\n", memory[loc]);
        loc++;
    } 
}


void dump_memory(int *memory){
    for(int i = 0; i < MAX_MEMORY; i++){
        printf("%d\n", memory[i]);
        if(memory[i] == 4300) break;
    }
}


int write_machine_code_to_file(FILE *fp, int *memory){

    if(fp){
        for(int i = 0; i<MAX_MEMORY; i++){
           fprintf(fp, "%d\n", memory[i]);
           if(memory[i] == 4300) break;
        }
        fflush(fp);
    }

    return 0;
}