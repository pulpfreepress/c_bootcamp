/*Implementation file for simplesim library.*/

#include "simplesim_mmu.h"
#include <stdio.h>
#include <stdlib.h>


CPU cpu;
MMU mmu;

void initialize_cpu(CPU * cpu){
    cpu->accumulator = 0;
    cpu->program_counter = 0;
    for(int i = 0; i < MAX_MEMORY; i++){
        cpu->memory[i] = 0;
    }
}


void initialize_mmu(MMU * mmu){
    for(int i = 0; i < MAX_PROGRAMS; i++){
        mmu->lookup_table[i].offset = 0;
        mmu->lookup_table[i].process.id = 0;
        for(int j = 0; j < VIRTUAL_MEMORY; j++){
            mmu->lookup_table[i].process.code[i] = 0;
        }

    }
}


void load_program(CPU * cpu, char * filename){


}

void dump_cpu_state(CPU * cpu){
    printf("********* CPU STATE *********\n");
    printf("Max Memory:      %0.4d\n", MAX_MEMORY);
    printf("Virtual Memory:  %0.4d\n", VIRTUAL_MEMORY);
    printf("Max Programs:    %0.4d\n", MAX_PROGRAMS);
    printf("Accumulator:     %0.4f\n", cpu->accumulator);
    printf("Program Counter: %d\n", cpu->program_counter);
    printf("********* MEMORY *********\n");
    for(int i = 1; i <= MAX_MEMORY; i++){
        if((i % 20) == 0){
            printf("%04.0f\n", cpu->memory[i-1]);
        } else {
            printf("%04.0f ", cpu->memory[i-1]);
        }
    }
}

void load_demo(CPU * cpu){
    mmu.lookup_table[0].offset = 100;
    mmu.lookup_table[0].process.id = 1;
    mmu.lookup_table[0].process.code[0] = 1010;
    mmu.lookup_table[0].process.code[1] = 1011;
    mmu.lookup_table[0].process.code[2] = 2010;
    mmu.lookup_table[0].process.code[3] = 3010;
    mmu.lookup_table[0].process.code[4] = 2112;
    mmu.lookup_table[0].process.code[5] = 1112;
    mmu.lookup_table[0].process.code[6] = 4020;
    mmu.lookup_table[0].process.code[20] = 4300;


    for(int i = 0; i<VIRTUAL_MEMORY; i++){
        cpu->memory[i + mmu.lookup_table[0].offset] = mmu.lookup_table[0].process.code[i];
    }
}


void initialize_simulation(){
    initialize_cpu(&cpu);
    initialize_mmu(&mmu);
    load_demo(&cpu);
    
}


void run(){
    initialize_simulation();
    for(int i = 0; i < MAX_PROGRAMS; i++){
        if(mmu.lookup_table[i].process.id > 0){
            run_process(mmu.lookup_table[i].process.id);
        }
        else{
            break;
        }
    }

}


void run_process(int process_id){

   
    int keepgoing = TRUE;

    int offset = 0;

    for(int i = 0; i < MAX_PROGRAMS; i++){
        if(mmu.lookup_table[i].process.id == process_id){
            offset = mmu.lookup_table[i].offset;
            break;
        }
    }

    cpu.program_counter = offset;

    dump_cpu_state(&cpu);
    
    while(keepgoing){
        int instruction = (int)cpu.memory[cpu.program_counter++];

        int opcode = instruction / 100;
        int operand = instruction % 100;

        switch(opcode){
            case READ: {
                printf("Please enter a number: ");
                double input = 0;
                scanf("%lf", &input);
                cpu.memory[operand+offset] = input;
                dump_cpu_state(&cpu);
                break;
            }
            
            case WRITE: {
                printf("%f\n", cpu.memory[operand+offset]);
                break;
            }

            case LOAD: {
                cpu.accumulator = cpu.memory[operand+offset];
                dump_cpu_state(&cpu);
                break;
            }

            case STORE: {
                cpu.memory[operand+offset] = cpu.accumulator;
                dump_cpu_state(&cpu);
                break;
            }

            case ADD: {
                cpu.accumulator += cpu.memory[operand + offset];
                dump_cpu_state(&cpu);
                break;
            }

            case SUB: {
                cpu.accumulator -= cpu.memory[operand + offset];
                dump_cpu_state(&cpu);
                break;
            }

            case MUL: {
                cpu.accumulator *= cpu.memory[operand + offset];
                dump_cpu_state(&cpu);
                break;
            }

            case DIV: {
                cpu.accumulator /= cpu.memory[operand + offset];
                dump_cpu_state(&cpu);
                break;
            }

            case JMP: {
                printf("DEBUG: PC -->  %d\n", cpu.program_counter);
                printf("DEBUG: OPERAND --> %d\n", operand);
                printf("DEBUG: OFFSET --> %d\n", offset);
                printf("DEBUG: OPERAND + OFFSET --> %d\n", operand + offset);

                cpu.program_counter = operand + offset;
                dump_cpu_state(&cpu);
                break;
            }

            case JMPZ: {
                if (cpu.accumulator == 0){
                    cpu.program_counter = operand + offset;
                } 
                dump_cpu_state(&cpu);
                break;
            }

            case JMPN: {
                if (cpu.accumulator < 0){
                    cpu.program_counter = operand + offset;
                }
                dump_cpu_state(&cpu);
                break;
            }

            case HALT:{
                keepgoing = FALSE;
                printf("Exiting the program...\n");
                break;
            }
            default:{
                keepgoing = FALSE;
            }
        }
    } // end while

    dump_cpu_state(&cpu);



}