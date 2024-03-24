/* Demonstrate reading an entire file into a dynmically allocated character array. */

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes */

/* read_file() — Returns a pointer to a character array containing
   the entire contents of the file.
*/
char *read_file(FILE *file, char *buffer);

int main(){

	FILE *fp = NULL;
	char *input_string = NULL;

	fp = fopen("output.txt", "r");

	if(fp){

		// read file into input_string buffer
		input_string = read_file(fp, input_string);
		// print input_strring contents to console
		printf("%s\n", input_string);
	}

	// Deallocate  character array memory
	if(input_string){
		free(input_string);
		input_string = NULL;
	}

	// Close file
	if(fp){
		fclose(fp);
		fp = NULL;
	}

	return 0;
}

/* read_file() */
char *read_file(FILE *file, char *buffer){
	fseek(file, 0, SEEK_END); // Seek to EOF
	int length = ftell(file); // Get length of file in bytes
	fseek(file, 0, SEEK_SET); // Seek to beginning of file
	printf("File length = %d\n", length);
	buffer = malloc(sizeof(char) * (length + 1)); // Dynamically allocate buffer space
	if(buffer){
		size_t elements_read = fread(buffer, sizeof(char), length, file); // read file as chars
		printf("Elements read = %lu\n", elements_read);
	}
	return buffer;

}


