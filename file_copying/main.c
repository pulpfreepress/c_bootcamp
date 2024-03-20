/* From The C Programming Language by K & R -- Section 1.5.1 */

#include <stdio.h>

int main() {
    int c;

    while((c = getchar()) != EOF){
        putchar(c);
    }

    return 0;
}
