// Demonstrate Random Access File IO


#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *fp = fopen("test.data", "w+");

    if(!fp){
        printf("Problem opening file for writing.\n");
        return 1;
    }

    fputs("Now is the time for all good men to come to the aid of their country!", fp);

    fclose(fp);

    // Pause to manually read file
    printf("Examine file -- then hit any key to continue...\n");

    char input[20];
    scanf("%s", input);

    fp = fopen("test.data", "r+");

    if(!fp){
        printf("Problem opening file for writing.\n");
        return 1;
    }

    // SEEK_END sets the file pointer to the end of the file. 
    // SEEK_SET sets the file pointer to the beginning of the file.

    fseek(fp, -11, SEEK_END);
    fputs(" beloved universe!", fp);

    fclose(fp);


    return 0;
}
