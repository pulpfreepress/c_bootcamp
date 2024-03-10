/* Demonstrate formatted console output with printf(). */

#include <stdio.h>

int main(){
	printf("Hello World!\n");
	printf("%s\n", "Hello World!");
	printf("%s %s\n", "Hello", "World!");
	printf("%12d\n", 100);
	printf("%-12d\n", 100);
	printf("%12f\n", 100.001);
	printf("%12.3f\n", 100.001);
	printf("%12.3f\n", 100.006);
	printf("%12.2f\n", 100.006);
	printf("%12.2f\t%12.2f\n", 100.006, 200.298);

	return 0;
}