/* Demonstrate C structures (structs) */

#include <stdio.h>
#include <string.h>

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
void print_people_array(Person *array, int size);


int main(){

	Person p1;
	Person people_array[ARRAY_LENGTH];

	strcpy(p1.first_name, "Rick");
	strcpy(p1.middle_name, "W");
	strcpy(p1.last_name, "Miller");

	printf("First Name: %s\n", p1.first_name);
	printf("Middle Name: %s\n", p1.middle_name);
	printf("Last Name: %s\n", p1.last_name);

	int total_bytes = sizeof(people_array);
	printf("Total size of array in bytes: %d \n", total_bytes);

	int person_struct_size = sizeof(Person);
	printf("Size of Person struct in bytes: %d\n", person_struct_size);

	int people_array_elements = total_bytes/person_struct_size;
	printf("Element count in people_array: %d\n", people_array_elements);

	people_array_elements = (sizeof(people_array)/sizeof(Person));
	printf("Element count in people_array: %d\n", people_array_elements);

	for(int i = 0; i < people_array_elements; i++){
		strcpy(people_array[i].first_name, "John");
		strcpy(people_array[i].middle_name, "J");
		strcpy(people_array[i].last_name, "Doe");
	}

	printf("First Name: %s\n", people_array[0].first_name);
	printf("Middle Name: %s\n", people_array[0].middle_name);
	printf("Last Name: %s\n", people_array[0].last_name);

	print_people_array(people_array,(sizeof(people_array)/sizeof(Person)));

	return 0;
}

void print_people_array(Person *array, int size){
	for(int i = 0; i < size; i++ ){
		printf("Person %d: %s\t %s\t %s\n", i, 
		   array[i].first_name, array[i].middle_name, array[i].last_name);
	}


}
