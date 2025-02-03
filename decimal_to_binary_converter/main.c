/*************************************************************
* Converts decimal to binary using repeated division algorithm
**************************************************************/

#include <stdio.h>

#define MAX_BINARY_BITS 32

// Function declarations
void int_to_bin(int n, char*);


int main(){

    char bin[MAX_BINARY_BITS + 1] = "";
    for(int i=0; i<MAX_BINARY_BITS; i++){
        bin[i] = '0';
    }
    

    int input = 0;
    printf("%s", "Enter number: ");
    scanf("%d", &input);
    int_to_bin(input, bin);
    printf("%s\n", bin);

    return 0;
}


void int_to_bin(int n, char bin[]){
    int result = 0;
    int remainder = 0;
    if(n == 0) return;
    for(int i = 0; i < MAX_BINARY_BITS; i++){
        if(n == 0){
            remainder = 0;
            result = 0;
            return;
        }else if(n == 1){
            remainder = 1;
            result = 0;
        } else if(n > 1){
            result = n / 2;
            remainder = n % 2;
        }

        switch(remainder){
            case 0: {
               bin[MAX_BINARY_BITS - i] = '0'; 
               n = result;
               remainder = 0;
               break;
            }
            case 1: {
                bin[MAX_BINARY_BITS - i] = '1'; 
                n = result;
                remainder = 0;
                break;
            }
        }

        if(result == 0) return;

    }

    

}
