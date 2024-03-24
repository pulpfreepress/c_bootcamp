/* Demonstrate reading an entire text file into a dymamically-allocated
   character array.
*/

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

/* read_file() — Returns pointer to character array containing
the entire contents of the file.
Parameters
*/
char *read_file(FILE *file, char *buffer); 

int main(){

	FILE *fp = NULL;
	char *input_string = NULL;

	fp = fopen("output.txt", "r");

	if(fp){
		input_string = read_file(fp, input_string);
		printf("%s\n", input_string);
	} 

	// Deallocate character array memory
	if(input_string){
		free(input_string);
		input_string = NULL;
	}

	// Deallocate file pointer
	if(fp){
		fclose(fp);
		fp = NULL;
	}

	return 0;
}


char *read_file(FILE *file, char *buffer){
	fseek(file, 0, SEEK_END);
	int length = ftell(file);
	fseek(file, 0, SEEK_SET);
	printf("File length = %d\n", length);
	buffer = malloc(sizeof(char) * (length + 1));
	if(buffer){
		size_t elements_read = fread(buffer, sizeof(char), length, file);
		printf("Elements read: %lu\n", elements_read);
	}
	return buffer;
}

