/******************************** 

Demonstrate formatted console output with printf(). 

********************************/

// This is a single-line comment

#include <stdio.h>

int main(){
	// Comment
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

	printf("%x\n", 10);

	return 0;
}