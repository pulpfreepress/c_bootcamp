/*Implementation file for simplesim library.*/

#include "simplesim.h"
#include <stdio.h>
#include <stdlib.h>


CPU cpu;

void initialize_cpu(CPU * cpu){
    cpu->accumulator = 0;
    cpu->program_counter = 0;
    for(int i = 0; i < MAX_MEMORY; i++){
        cpu->memory[i] = 0;
    }
}


void load_program(CPU * cpu, char * filename){


}

void dump_cpu_state(CPU * cpu){
    printf("********* CPU STATE *********\n");
    printf("Accumulator:     %0.4f\n", cpu->accumulator);
    printf("Program Counter: %d\n", cpu->program_counter);
    printf("********* MEMORY *********\n");
    for(int i = 1; i <= MAX_MEMORY; i++){
        if((i % 10) == 0){
            printf("%04.0f\n", cpu->memory[i-1]);
        } else {
            printf("%04.0f ", cpu->memory[i-1]);
        }
    }
}

void load_demo(CPU * cpu){
    cpu->memory[0] = 1010;
    cpu->memory[1] = 1011;
    cpu->memory[2] = 2010;
    cpu->memory[3] = 3011;
    cpu->memory[4] = 2112;
    cpu->memory[5] = 1112;
    cpu->memory[6] = 4020;
    cpu->memory[20] = 4300;
}

void run(){
    initialize_cpu(&cpu);
    load_demo(&cpu);
    dump_cpu_state(&cpu);

    int keepgoing = TRUE;

    while(keepgoing){
        int instruction = (int)cpu.memory[cpu.program_counter++];

        int opcode = instruction / 100;
        int operand = instruction % 100;

        switch(opcode){
            case READ: {
                printf("Please enter a number: ");
                double input = 0;
                scanf("%lf", &input);
                cpu.memory[operand] = input;
                dump_cpu_state(&cpu);
                break;
            }
            
            case WRITE: {
                printf("WRITE Not Implemented...\n");
                break;
            }

            case LOAD: {
                cpu.accumulator = cpu.memory[operand];
                dump_cpu_state(&cpu);
                break;
            }

            case STORE: {
                cpu.memory[operand] = cpu.accumulator;
                break;
            }

            case ADD: {
                cpu.accumulator += cpu.memory[operand];
                break;
            }

            case SUB: {
                cpu.accumulator -= cpu.memory[operand];
                break;
            }

            case MUL: {
                cpu.accumulator *= cpu.memory[operand];
                break;
            }

            case DIV: {
                cpu.accumulator /= cpu.memory[operand];
                break;
            }

            case JMP: {
                cpu.program_counter = cpu.memory[operand];
                break;
            }

            case JMPZ: {
                if (cpu.accumulator == 0){
                    cpu.program_counter = cpu.memory[operand];
                } 
                break;
            }

            case JMPN: {
                if (cpu.accumulator < 0){
                    cpu.program_counter = cpu.memory[operand];
                }
                break;
            }

            case HALT:{
                keepgoing = FALSE;
                break;
            }
            default:{
                keepgoing = FALSE;
            }
        }
    } // end while

    dump_cpu_state(&cpu);



}