/* Temperature Converter.*/

#include <stdio.h>

int main(){
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%12s\t%12s\n", "Fahrenheit", "Celsius");
    while (fahr <= upper){
        celsius = 5 * ((fahr - 32) / 9);
        printf("%12d\t%12d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}