/*************************************************************
 * Demonstrate use of sizeof() function to display type sizes
**************************************************************/

#include <stdio.h>

int main(){

    // Size of fundamental types
    puts("Size of Fundamental Types in Bytes");
    puts("------------------------------------");
    printf("%20s\t%2lu\n", "sizeof(char)", sizeof(char));
    printf("%20s\t%2lu\n", "sizeof(short)", sizeof(short));
    printf("%20s\t%2lu\n", "sizeof(int)", sizeof(int));
    printf("%20s\t%2lu\n", "sizeof(long)", sizeof(long));
    printf("%20s\t%2lu\n", "sizeof(float)", sizeof(float));
    printf("%20s\t%2lu\n", "sizeof(double)", sizeof(double));

    // Size of variablles and arrays
    int a;
    long b;
    int int_arr[] = {1, 2, 3, 4, 5};
    long long_arr[] = {1, 2, 3, 4, 5};

    puts("\n");
    puts("Size of Variables and Arrays in Bytes");
    puts("------------------------------------");
    printf("%20s\t%2lu\n", "sizeof(int a)", sizeof(a));
    printf("%20s\t%2lu\n", "sizeof(long b)", sizeof(b));
    printf("%20s\t%2lu\n", "sizeof(int_arr[5])", sizeof(int_arr));
    printf("%20s\t%2lu\n", "sizeof(long_arr[5])", sizeof(long_arr));

    return 0;
}