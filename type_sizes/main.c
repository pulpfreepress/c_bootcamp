/*************************************
 * Demonstrates the sizeof() function.
**************************************/


#include <stdio.h>

int main(){

	// char, short, int, long, float, double

	printf("%20s\t%2lu\n", "sizeof(char)", sizeof(char));
	printf("%20s\t%2lu\n", "sizeof(short)", sizeof(short));
	printf("%20s\t%2lu\n", "sizeof(int)", sizeof(int));
	printf("%20s\t%2lu\n", "sizeof(long)", sizeof(long));
	printf("%20s\t%2lu\n", "sizeof(float)", sizeof(float));
	printf("%20s\t%2lu\n", "sizeof(double)", sizeof(double));

	// unsigned

	printf("%20s\t%2lu\n", "sizeof(unsigned short)", sizeof(unsigned short));
	printf("%20s\t%2lu\n", "sizeof(unsigned int)", sizeof(unsigned int));
	printf("%20s\t%2lu\n", "sizeof(unsigned long)", sizeof(unsigned long));

	printf("---------------------------------------------------\n");

	int a;
	long b;
	int int_array[5];
	long long_array[5];

	printf("%s\n", "Size of variables and arrays.");
	printf("%20s\t%2lu\n", "sizeof(a)", sizeof(a));
	printf("%20s\t%2lu\n", "sizeof(b)", sizeof(b));
	printf("%20s\t%2lu\n", "sizeof(int_array)", sizeof(int_array));
	printf("%20s\t%2lu\n", "sizeof(long_array)", sizeof(long_array));

	for(int i = 0; i<5; i++){
		long_array[i] = 0;
		printf("%ld ", long_array[i]);
	}

	return 0;
}