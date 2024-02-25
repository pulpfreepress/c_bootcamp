/* From The C Programming Language by K & R -- Section 1.5.1 */

#include <stdio.h>

int main() {
    int c;

    c = getchar();
    while(c != EOF){
        putchar(c);
        c = getchar();
    }

    return 0;
}
