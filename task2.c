#include <stdio.h>
#include <ctype.h>

// declares functions
float fToC(float temp);
float cToF(float temp);
int printTempCat(float temp);

int main() {
    // declares variables
    float temp, cTemp;
    char scale, conv;

    // gets the temp, the original scale, and the scale to convert to
    printf("Enter the temperature value: ");
    scanf("%f", &temp);
    printf("Enter the original scale (C, F, or K): ");
    scanf(" %c", &scale);
    printf("Enter the scale to convert to (C, F, or K): ");
    scanf(" %c", &conv);

    // switch statement to get the conversion temp depending on the input scale
    switch (toupper(scale)) {
        case 'F':
            cTemp = fToC(temp); // calls fToC function to get cTemp
            break;
        case 'C':
            cTemp = temp;
            break;
        case 'K':
            cTemp = temp - 273;
            break;
    }

    // switch statement to print the converted temperature depending on the output scale
    switch (toupper(conv)){
        case 'F':
            printf("Converted Temperature: %f F\n", cToF(cTemp)); // uses cToF funciton to convert to farenheit
            break;
        case 'C':
            printf("Converted Temperature: %f C\n", cTemp);
            break;
        case 'K':
            printf("Converted Temperature: %f K\n", cTemp + 273);
            break;
    }

    // calls printTempCat function to pring temp categories and weather alerts
    printTempCat(cTemp);
}

// function to return the celcius temp from an input farenheit temp
float fToC(float temp) {
    return ((temp - 32) * 5/9);
}

// function to return the farenheit temp from an input celcius temp
float cToF(float temp) {
    return ((temp * 9/5) + 32);
}

// function that prints the corresponding temperature category and weahter advisory for the celcius temp given
int printTempCat(float temp) {
    printf("Temperature category: ");
    if (temp < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Wear Heavy Clothing\n");
    } 
    else if ((0 <= temp) && (temp < 10)) {
        printf("Cold\n");
        printf("Weather advisory: Bring a Jacket\n");
    }
    else if ((10 <= temp) && (temp < 25)){
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the Weather\n");
    }
    else if ((25 <= temp) && (temp < 35)) {
        printf("Hot\n");
        printf("Weather advisory: Drink Lots of Water\n");
    }
    else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Try to Stay in the Shade or Inside\n");
    }
    return 1;
}
