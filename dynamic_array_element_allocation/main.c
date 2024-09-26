/* Demonstrate dynamic array element allocation. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 25
#define ARRAY_LENGTH  10

/* Define person structure */
struct person {
	char first_name[MAX_STRING_LENGTH];
	char middle_name[MAX_STRING_LENGTH];
	char last_name[MAX_STRING_LENGTH];
};

/* Create new type with typedef */
typedef struct person Person;

/* Declare function prototype. */
void print_people_array(Person **array, int size);


int main(){

	// Declare pointer to Person pointer.
	Person **people_array = NULL;

	// Dynamically allocate memory for the array.
	people_array = malloc(sizeof(Person *) * ARRAY_LENGTH);

	// If the memory allocation for people_array succeeded...
	if(people_array){

		// Sets each array element to NULL
		for(int i = 0; i < (sizeof(people_array)/sizeof(Person *)); i++){
			people_array[i] = NULL;
		}

		// Allocate a structure and assign to first element.
		people_array[0] = malloc(sizeof(Person));

		// If the Person structure memory allocatioin is successful...
		if(people_array[0]){
			strcpy(people_array[0]->first_name, "Coralie");
			strcpy(people_array[0]->middle_name, "Sarah");
			strcpy(people_array[0]->last_name, "Miller");

			printf("First Name: %s\n", people_array[0]->first_name);
			printf("Middle Name: %s\n", people_array[0]->middle_name);
			printf("Last Name: %s\n", people_array[0]->last_name);


		} else {
			printf("Memory allocation for Person object failed.\n");
		}

		printf("********* Calling print_people_array() function...\n");

		print_people_array(people_array, (sizeof(people_array)/sizeof(Person *)));

	
		// First, free up memory for each instance if not NULL
		for(int i = 0; i < (sizeof(people_array)/sizeof(Person *)); i++ ){
			if(people_array[i]){
				free(people_array[i]);
			}
		}

		// Free memory for the array itself.
		free(people_array);

	} else {

		printf("Memory allocation for people_array failed.\n");
	}

	return 0;
}

void print_people_array(Person **array, int size){
	for(int i = 0; i < size; i++){
		if(array[i]){
			printf("Person %d: %s\t%s\t%s\n", i, 
					array[i]->first_name, array[i]->middle_name, array[i]->last_name);
		}
	}

}