/***********************************************************
* Demonstrate C variable declaration, naming, and usage.
***********************************************************/

#include <stdio.h>

int main(){
    int student_count;              // Declaration
    student_count = 10;             // Initialization
    char capital_letter = 'Y';      // Declaration and Initialization Combined
    float average = 10.1234;
    char first_name[] = "Rick";     // A string is an array of chars
    char *last_name = "Miller";     // Equivalent, but more about pointers later

    printf("Student Count = %d\n", student_count);
    printf("Capital Letter = %c\n", capital_letter);
    printf("Average = %f\n", average);
    printf("Name = %s\n", first_name);
    printf("Name = %s\n", last_name);
    printf("-------------------------------------\n");

    int some_ascii_value = 65;
    printf("Some ASCII Value: %c\n", (char)some_ascii_value);

    return 0;
}
