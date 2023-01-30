#include <stdio.h>

/*print the conversion table for Fahrenheit to Celsius*/
main() {

    float fahr, celsius;         
    int lower, upper, step;

    lower = 0;                  
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Celsius\t    Fahrenheit\n----------------------\n");

    while (fahr <= upper) {
        
        celsius = 5 * (fahr - 32) / 9;
        printf("    %3.0f\t\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;

    }

    printf("\n\nFahrenheit\tCelsius\n-----------------------\n");

    for (fahr = 300; fahr >= lower; fahr = fahr - 20)
        printf("     %3.1f\t    %3.0f\n", (5.0 / 9.0) * (fahr - 32), fahr);
}