/******************************** 

Demonstrate formatted console output with printf(). 

********************************/

// This is a single-line comment

#include <stdio.h>

// Function declarations
void print_stuff();

int main(){
	printf("main() called...\n");
	print_stuff();
	printf("Back in main()...\n");
	printf("Exiting program...\n");

	return 0;
}

// Function definition
void print_stuff(){
    // Comment
	printf("print_stuff() called...\n\n");
	printf("Hello World!\n"); // Comment
	printf("%s\n", "Hello World!");
	printf("%s %s\n", "Hello", "World!");
	printf("%12d\n", 100);
	printf("%-12d\n", 100);
	printf("%12f\n", 100.001);
	printf("%12.3f\n", 100.001);
	printf("%12.3f\n", 100.006);
	printf("%12.2f\n", 100.006);
	printf("%12.2f\t%12.2f\n", 100.006, 200.298);

}