/* Demonstrate pointers. */

#include <stdio.h>

int main(){
    int a = 3;
    int* pa = &a;

    printf("a = %d\n", a);
    printf("address of a = %p\n", &a);

    printf("a = %d\n", *pa);
    printf("address of a = %p\n", pa);



    return 0;
}