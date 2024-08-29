#include "stdio.h"

int main()
{
    unsigned char a=0x64;
    int b=0xFAFA;
	
    printf("value of a: %X [%x]\n",a,a);
    printf("value of b: %X [%x]\n",b,b);
    printf("value of b: %X [%X]\n",b,b);
	
    return 0;
}
