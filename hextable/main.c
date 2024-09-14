#include <stdio.h>


int main(){

    for(int i=0; i<256; i++){
        printf("%4d --> %4x\n", i, i);
    }

    return 0;
}