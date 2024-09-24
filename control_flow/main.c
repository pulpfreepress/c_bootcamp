/* Demonstrate C Control-Flow Statements. */

#include <stdio.h>


int main(){

	/***** Statements and Blocks *****/
	// An expression becomes a statement when it is
	// terminated by a semicolon..
	int i = 0;
	printf("i == %d\n", i);

	// Braces group declarations and statements into
	// compound statements (a.k.a. blocks)
	{
		int i = 3;
		printf("Inner scope i == %d\n",i);
	}

	printf("Outer scope i == %d\n", i);

	printf("************* Branching Statements **************\n");
	// if-else -- Used to branch to a different path of execution
	// based on a conditional expression.

	if(i < 5){
		printf("%d is less than 5\n", i);
	}else{
		// else clause is optional
		printf("%d is equal to or greater than 5\n", i);
	}

	// else-if -- Used for multiple branching options.
	if(i < 5){
		printf("%d is less than 5\n", i);
	} else if(i == 10) {
		printf("%d is equal to 10\n", i);
	} else {
		printf("Hello World! i == %d\n", i);
	}

	// switch -- Multi-way decision statement
	switch(i){
		case 0: // Will fall through to next case
		case 1:
		case 2:
		case 3:
		case 4: {
			printf("%d is less than 5\n", i);
			break;
		}
		case 10: {
			printf("%d is equal to 10\n", i);
			break;
		}
		default: {
			printf("Hello World! i == %d\n", i);
		}
	}

	printf("************* Looping Statements **************\n");
	// for statement - Combines counter variable initialization,
	// conditional expression evaluation, and counter variable
	// increment in a convenient syntax.
	printf("for statement...\n");

	for(int i = 0; i < 15; i++){
		if(i < 5){
			printf("%d is less than 5\n", i);
		}else{
			// else clause is optional
			printf("%d is equal to or greater than 5\n", i);
		}
	}

	// while statement - Execute a block of code while
	// conditional expressions is true.
	// Conditional expression may evaluate to false initially,
	// which would prevent the while statement from executing.

	printf("\nwhile statement...\n");
	i = 0; // Just to make sure...

	while(i <= 10){
		switch(i){
			case 0:
			case 1:
			case 2:
			case 3:
			case 4: {
				printf("%d is less than 5\n", i);
				break;
			}
			case 10: {
				printf("%d is equal to 10\n", i);
				break;
			}
			default: {
				printf("Hello World! i == %d\n", i);
			}
		}
		i++;
	}


	// do-while - Executes block of code at least once
	// and then evalutates the conditional expression.
	printf("\ndo-while statement...\n");

	i = 0;
	do{
		if(i < 5){
			printf("%d is less than 5\n", i);
		} else if(i == 10) {
			printf("%d is equal to 10\n", i);
		} else {
			printf("Hello World! i == %d\n", i);
		}
	} while(i++ < 10);

	return 0;
}