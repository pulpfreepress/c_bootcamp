#include <stdio.h>

#define SIZE  5

int main(){

    int grades[SIZE] = {1, 2, 3, 4, 5};

    // For Statement
    
    for(int i = 0; i < 5; i++){
        printf("%2d ", i);
    }

    printf("\n");

    for(int i = 0; i < 5; i++){
        printf("%2d ", grades[i]);
    }

    // While Statement
    printf("\n");

    int i = 0;
    while(i++ < 5){
        printf("%2d ", i);     
    }

    printf("\n");

    i = 0;
    do {
        printf("%2d ", grades[i]); 
    } while(i++ < 5);


    return 0;
} // end main()