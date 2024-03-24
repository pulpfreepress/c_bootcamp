/* Demonstrate File I/O */

#include <stdio.h>

/* Function prototype. */
int save_message_to_file(char *message, FILE *stream);

int main(){

	FILE *fp = NULL;
	char message[] = "Hello World!\n";

	fp = fopen("output.txt", "a");

	printf("Characters written to file:  = %d\n", save_message_to_file(message, fp));
	printf("Characters written to file:  = %d\n", save_message_to_file("Oh, I love C programming!\n", fp));
	printf("Characters written to file:  = %d\n", save_message_to_file("March is going out like a lion!\n", fp));
	printf("Characters written to file:  = %d\n", save_message_to_file("I hope you enjoyed this video!!\n", fp));

	/* Close file ALWAYS! Don't forget! */
	fclose(fp);
	fp = NULL;

	return 0;
}

int save_message_to_file(char *message, FILE *stream){

	int result = 0;
	if(stream){
		result = fputs(message, stream);
	}
	return result;
}