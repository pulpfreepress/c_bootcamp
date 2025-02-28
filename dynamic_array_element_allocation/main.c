/* Demonstrate dynamic array element allocation. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 26
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
	Person **people_array = NULL;

	people_array = malloc(sizeof(Person *) * ARRAY_LENGTH);

	if(people_array){

		for(int i = 0; i < ARRAY_LENGTH; i++){
			printf("Is NULL: %s\n", people_array[i] == NULL ? "Y" : "N");
		}

		printf("%s\n", "--------------------------");
		
		for(int i = 0; i < ARRAY_LENGTH; i++){
			people_array[i] = NULL;
		}

		for(int i = 0; i < ARRAY_LENGTH; i++){
			printf("Is NULL: %s\n", people_array[i] == NULL ? "Y" : "N");
		}
	
		people_array[0] = malloc(sizeof(Person));

		if(people_array[0]){
			strcpy(people_array[0]->first_name, "Coralie");
			strcpy(people_array[0]->middle_name, "Sarah");
			strcpy(people_array[0]->last_name, "Miller");
		}

		printf("First Name: %s\n", people_array[0]->first_name);
		printf("Middle Name: %s\n", people_array[0]->middle_name);
		printf("Last Name: %s\n", people_array[0]->last_name);

		for(int i = 1; i < ARRAY_LENGTH; i++){
			people_array[i] = malloc(sizeof(Person));
			if(people_array[i]){
				strcpy(people_array[i]->first_name, "Jane");
				strcpy(people_array[i]->middle_name, "J.");
				strcpy(people_array[i]->last_name, "Doe");
			}
			
		}

		print_people_array(people_array, ARRAY_LENGTH);

		for(int i = 0; i < ARRAY_LENGTH; i++){
			if(people_array[i]){
				free(people_array[i]);
			}
		}

		free(people_array);

	} else {
		printf("Memory allocation failed for people_array.");
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


