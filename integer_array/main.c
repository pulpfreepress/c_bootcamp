/* A Short C Program to Process an Array of Integers. */

#include <stdio.h>

int main(){

	int total = 0;
	int numbers[] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0; i < 10; i++){
		total += numbers[i];
	}

	printf("Total = %d", total);

	return 0;
}