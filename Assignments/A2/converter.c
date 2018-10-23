//
//  converter.c
//  CS2211Asn2
//
//  Created by Hasan Ahmed on 2018-10-01.
//

//include the header file
#include "converter.h"

//create function to convert between km and miles
int convertKmAndM() {
    //ask user for the char input for whether they want K for kilometres or M for miles
    char pickType;
    printf("Enter K if you are entering in kilometres, or M for miles: ");
    scanf(" %c", &pickType);
    //procedure if user chooses to enter in kilometres
    if (pickType == 'K' || pickType == 'k') {
        float distKm;
        printf("Enter the distance in km: ");
        scanf("%f", &distKm);
        //calculate the miles from km
        float distMl = distKm / 1.60934;
        //output calculation to user
        printf("%0.02f km is %0.02f in miles!\n", distKm, distMl);
    }
    //procedure if user chooses to enter in miles
    else if (pickType == 'M' || pickType == 'm') {
        float distMl;
        printf("Enter the distance in miles: ");
        scanf("%f", &distMl);
        //calulate the km from miles
        float distKm = distMl * 1.60934;
        //output calculation to user
        printf("%0.02f miles is %0.02f in km!\n", distMl, distKm);
    }
    //if user inputs incorrect char
    else {
        printf("You did not enter a valid input!");
    }
    //call main method again
    //main();
    return 0;
}

//create function to convert between feet and meters
int convertFeetAndMeters() {
    //ask user for the char input for whether they want F for feet or M for meters
    char pickType;
    printf("Enter F if you are entering in feet, or M for meters: ");
    scanf(" %c", &pickType);
    //procedure if user chooses to enter in feet
    if (pickType == 'F' || pickType == 'f') {
        float distFeet;
        printf("Enter the distance in feet: ");
        scanf("%f", &distFeet);
        //calculate the meters from feet
        float distMeters = distFeet * 0.305;
        //output calculation to user
        printf("%0.02f feet is %0.02f in meters!\n", distFeet, distMeters);
    }
    //procedure if user chooses to enter in meters
    else if (pickType == 'M' || pickType == 'm') {
        float distMeters;
        printf("Enter the distance in meters: ");
        scanf("%f", &distMeters);
        //calculate the feet from meters
        float distFeet = distMeters / 0.305;
        //output calculation to user
        printf("%0.02f meters is %0.02f in feet!\n", distMeters, distFeet);
    }
    //if user inputs incorrect char
    else {
        printf("You did not enter a valid input!");
    }
    //call main method again
    main();
    return 0;
}

//create function to convert between cm and inches
int convertInchesAndCent() {
    //ask user for the char input for whether they want C for cm or I for inches
    char pickType;
    printf("Enter C if you are entering in centimetres, or I for inches: ");
    scanf(" %c", &pickType);
    //procedure if user chooses to enter in cm
    if (pickType == 'C' || pickType == 'c') {
        float distCent;
        printf("Enter the distance in centimetres: ");
        scanf("%f", &distCent);
        //calculate the inches from cm
        float distInch = distCent / 2.54;
        //output calculation to user
        printf("%0.02f centimetres is %0.02f in inches!\n", distCent, distInch);
    }
    //procedure if user chooses to enter in inches
    else if (pickType == 'I' || pickType == 'i') {
        float distInch;
        printf("Enter the distance in inches: ");
        scanf("%f", &distInch);
        //calculate the cm from inches
        float distCent = distInch * 2.54;
        //output calculation to user
        printf("%0.02f inches is %0.02f in centimetres!\n", distInch, distCent);
    }
    //if user inputs incorrect char
    else {
        printf("You did not enter a valid input!");
    }
    //call main method again
    main();
    return 0;
}

//create function to convert between celsius and fahrenheit
int convertCelsiusAndFaren() {
    //ask user for the char input for whether they want C for celsius or F for fahrenheit
    char pickType;
    printf("Enter C if you are entering in Celsius, or F for Fahrenheit: ");
    scanf(" %c", &pickType);
    //procedure if user chooses to enter in celsius
    if (pickType == 'C' || pickType == 'c') {
        float distCels;
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &distCels);
        //calculate the fahrenheit from celsius
        float distFarn = (distCels * 9/5) + 32;
        //output calculation to user
        printf("%0.02f degrees in Celsius is %0.02f degrees in Fahrenheit!\n", distCels, distFarn);
    }
    //procedure is user chooses to enter in fahrenheit
    else if (pickType == 'F' || pickType == 'f') {
        float distFarn;
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &distFarn);
        //calculate the celsius from fahrenheit
        float distCels = (distFarn * 5/9) - 32;
        //output calculation to user
        printf("%0.02f degrees in Fahrenheit is %0.02f degrees in Celsius!\n", distFarn, distCels);
    }
    //if user inputs incorrect char
    else {
        printf("You did not enter a valid input!");
    }
    //call main method again
    main();
    return 0;
}

//main method starting program
int main() {
    //create variable to hold selection
    int input;
    //ask user to choose a converter
    printf("Welcome to my Converter!\n Enter '1' for km and miles \n Enter '2' for feet and meters converter \n Enter '3' for inches and cm converter \n Enter '4' for celsius and fahrenheit \n Enter '5' to exit \n Enter a number from 1-5: ");
    //store selection into variable input
    scanf("%d", &input);
    //selection for km and miles converter
    if (input == 1) {
        convertKmAndM();
    }
    //selection for feet and meters converter
    else if (input == 2) {
        convertFeetAndMeters();
    }
    //selection for inches and cm converter
    else if (input == 3) {
        convertInchesAndCent();
    }
    //selection for celsius and fahrenheit converter
    else if (input == 4) {
        convertCelsiusAndFaren();
    }
    //selection to exit program
    else if (input == 5) {
        printf("Exiting program!\n");
        return 0;
    }
    //invalid input, try again
    else {
        printf("Invalid input, try again!\n");
        main();
    }
    return 0;
}


