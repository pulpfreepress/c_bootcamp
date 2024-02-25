/* Power Function | From The C Programming Language by K & R | Section 1.7 Functions */

#include <stdio.h>

/* Function Prototype */
int power(int, int);


int main(){

    for(int i = 0; i < 10; i++){
        printf("%d\t%d\n", i, power(2, i));
    }

    return 0;
}


int power(int base, int n){
    int p = 1;

    for (int i = 1; i <= n; ++i){
        p = p * base;
    }

    return p;
}


/* A More compact version enabled by call-by-value parameters.*/
/*
int power(int base, int n){

    int p;

    for(p = 1; n > 0; --n){
        p = p * base;
    }

    return p;
}
*/