/* Demonstrate Date and Times. */
/* NOTE: For this to work, an environment variable
   named DATEMSK must be set that points to a file
   that contains date format patterns. 
*/

#include <stdio.h>
#include <time.h>

typedef struct tm TIME;

int get_age(const char * birthday_string);

int main(){

	time_t t = time(NULL);
	TIME today = *localtime(&t);

	printf("%d-%02d-%02dT%02d:%02d:%02d\n", today.tm_year + 1900,
			today.tm_mon + 1, today.tm_mday, today.tm_hour, today.tm_min,
			today.tm_sec);
	printf("time_t = %ti\n", t);
	printf("Is Daylight Saving Time: %s\n", today.tm_isdst ? "Y" : "N");

	int age = get_age("1986-08-01");
	printf("Person's Age is: %d\n", age);
	age = get_age("1986-09-25");
	printf("Person's Age is: %d\n", age);
	age = get_age("1986-09-26");
	printf("Person's Age is: %d\n", age);
	age = get_age("1986-09-27");
	printf("Person's Age is: %d\n", age);

	return 0;
}

int get_age(const char * birthday_string){
	time_t t = time(NULL);
	TIME today = *localtime(&t);
	TIME bday = *getdate(birthday_string);
	int age = ((today.tm_year + 1900) - (bday.tm_year + 1900));
	if(today.tm_mon < bday.tm_mon){
		age -= 1;
	} else if ((today.tm_mon == bday.tm_mon) && (today.tm_mday < bday.tm_mday)){
		age -= 1;
	}
	return age;
}