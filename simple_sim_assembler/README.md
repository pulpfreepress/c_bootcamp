# Simple Sim Assembler

Converts Simple Sim assembly language into Simple Sim machine code. 

## Overview

- Reads in a simple sim assembler file: .ssasm
- Generates a simple sim machine language file: .ssprog
- The .ssprog file can be loaded into memory and executed

## Opcode Meanings


- #define READ 10   // Read number from console into memory location
- #define WRITE 11    // Write number from memory location to console
- #define LOAD 20     // Load value located at memory location into accumulator
- #define STORE 21    // Store value in accumulator to memory location
- #define ADD 30      // Add value from specified memory location to accumulator. Leave results in accumulator.
- #define SUB 31      // Subtract value found in memory location from accumulator. Leave results in accumulator.
- #define MUL 32      // Multiply accumulator by value found at memory location. Leave results in accumulator.
- #define DIV 33      // Divide accumulator by value at memory location. Leave results in accumulator.
- #define JMP 40      // Absolute jump to memory location indicated by PC.
- #define JMPN 41     // Jump to memory location indicated by PC if accumulator value is negative.
- #define JMPZ 42     // Jump to memory location indicated by PC if accumulator value is zero.
- #define HALT 43     // Stop program execution.


## Typical Simple Sim Assembler Program

```
START:  READ A
		READ B
		LOAD A
		ADD B
		STORE C
		WRITE C
		READ INC
		JMP LOOP
STOP:	HALT


A:      .DATA 0
B:      .DATA 0
C:      .DATA 0
INC:	.DATA 0
LOOP:	LOAD A
		SUB INC
		STORE A
		JMPZ STOP
		JMP LOOP

```

This should produce the following machine code output:

```
1011
1012
2011
3012
2113
1113
1014
4015
4300
0
0
0
0
0
0
2011
3114
2111
4208
4015
```