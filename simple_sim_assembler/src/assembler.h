/*Header file for simplesim assembler library.*/

#ifndef SIMPLESIM_H
#define SIMPLESIM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MEMORY 100

// OPCODES in Decimal
#define READ 10     // Read number from console into memory location
#define WRITE 11    // Write number from memory location to console
#define LOAD 20     // Load value located at memory location into accumulator
#define STORE 21    // Store value in accumulator to memory location
#define ADD 30      // Add value from specified memory location to accumulator. Leave results in accumulator.
#define SUB 31      // Subtract value found in memory location from accumulator. Leave results in accumulator.
#define MUL 32      // Multiply accumulator by value found at memory location. Leave results in accumulator.
#define DIV 33      // Divide accumulator by value at memory location. Leave results in accumulator.
#define JMP 40      // Absolute jump to memory location indicated by PC.
#define JMPN 41     // Jump to memory location indicated by PC if accumulator value is negative.
#define JMPZ 42     // Jump to memory location indicated by PC if accumulator value is zero.
#define HALT 43     // Stop program execution.


// Symbol structure
typedef struct {
    char label[20];
    int address;
} Symbol;





// Function prototypes

int get_opcode(const char *op);
void process_asm_file(FILE *fp, int *memory);
void add_symbol(const char *label, int address);
int write_machine_code_to_file(FILE *fp, int *memory);
void dump_memory(int *memory);





#endif // assembler.h