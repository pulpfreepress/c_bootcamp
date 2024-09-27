/*Header file for simplesim library.*/

#ifndef SIMPLESIM_H
#define SIMPLESIM_H


#include <stdio.h>

// Memory
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

#define TRUE 1
#define FALSE 0

struct cpu {
    int program_counter;
    double accumulator;
    double memory[MAX_MEMORY];
};

typedef struct cpu CPU;


// Function Prototypes
void run();
void initialize_cpu(CPU * cpu);
void load_program(CPU * cpu, char * filename);
void load_demo(CPU * cpu);
void dump_cpu_state(CPU * cpu);





#endif // simplesim.h