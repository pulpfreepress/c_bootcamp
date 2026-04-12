
#include "assembler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int memory[MAX_MEMORY];
Symbol symbol_table[MAX_MEMORY];
int symbol_count = 0;
int line_count = 0;


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
    return -1;
}


void add_symbol(const char *label, int address) {
    strcpy(symbol_table[symbol_count].label, label);
    symbol_table[symbol_count].address = address;
    symbol_count++;
}


int find_symbol(const char *label) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].label, label) == 0)
            return symbol_table[i].address;
    }
    return -1;
}


void process_asm_file(FILE *fp){
    char line[100];
    int loc = 0;

    while(fgets(line, sizeof(line), fp)){
        char label[20], op[20], operand[20];
        
        if (sscanf(line, "%[^:]: %s %s", label, op, operand) == 3) {
            add_symbol(label, loc);
        } else if (sscanf(line, "%[^:]: %s", label, op) == 2) {
            add_symbol(label, loc);
        }

        loc++;
        line_count++;
    }

    rewind(fp);

    generate_machine_code(fp);

    dump_symbol_table();

    } 



void generate_machine_code(FILE *fp) {
    char line[100];
    int loc = 0;

    while (fgets(line, sizeof(line), fp)) {
        char label[20] = "", op[20] = "", operand[20] = "";
        int fields = sscanf(line, "%[^:]: %s %s", label, op, operand);

        printf("DEBUG ONE: FIELDS: %d LABEL: %s OP: %s OPERAND: %s\n", fields, label, op, operand);

        if (fields == 1) {
            fields = sscanf(line, "%s %s", op, operand);
            printf("DEBUG TWO: FIELDS: %d OP: %s OPERAND: %s\n", fields, op, operand);
        }

        if (!strcmp(op, ".DATA")) {
            memory[loc] = atoi(operand);
            
        } else {
            int opcode = get_opcode(op);
            int addr = 0;

            if (fields > 1) {
                addr = find_symbol(operand);
                if (addr == -1) addr = atoi(operand);  
            }

            if(fields == -1){
                memory[loc] = 0;
            } else {
                memory[loc] = opcode * 100 + addr;
            }

            
        }

        loc++;
    }
}



void dump_memory(){
    for(int i = 0; i < line_count; i++){
        printf("%d\n", memory[i]);
        //if(memory[i] == 4300) break;
    }
}


void dump_symbol_table(){
    for(int i=0; i<symbol_count; i++){
        printf("Symbol: %s, Location: %d\n", symbol_table[i].label, symbol_table[i].address);
    }
}


int write_machine_code_to_file(FILE *fp){

    if(fp){
        for(int i = 0; i<line_count; i++){
           //if(memory[i] == -100 ) break;
           fprintf(fp, "%d\n", memory[i]);
           
        }
        fflush(fp);
    }

    return 0;
}