//
//  exp_calculator.c
//  CS2211Asn2
//
//  Created by Hasan Ahmed on 2018-10-02.
//

//include the header file
#include "exp_calculator.h"

//create function to retieve and feed the base number back
float getBase() {
    //create variable to store base number
    float baseNo;
    //ask user to enter a positive base number
    printf("Please enter a positive base no.: ");
    //scan input and store it as baseNo
    scanf("%f", &baseNo);
    //return baseNo back to main function to use in calculations
    return baseNo;
}

//create function to get retrieve and the exponent number back
int getExp() {
    //create variable to store exponent number
    int expNo;
    //ask user to enter an exponent number
    printf("Please enter the exponent no.: ");
    //scan input and store it as expNo
    scanf("%d", &expNo);
    //return expNo back to main function to use in calculations
    return expNo;
}

//create function to do recursive exponential calculation with base and exp as parameters
int doCalc(base, exp) {
    //if exponent is 0, return 1 as the answer
    if (exp == 0) {
        return 1;
    }
    //if exponent is 1, return the base as the answer
    else if (exp == 1) {
        return base;
    }
    //if exponent is even then run recursive function on half the exponent and multiply it by itself, returning answer
    else if (exp % 2 == 0) {
        float temp = doCalc(base, exp/2);
        return temp * temp;
    }
    //if exponent is off then run recursive function on half the exponent and multiply it by itself, and the base, returning the answer
    else {
        float temp = doCalc(base, exp/2);
        return temp * temp * base;
    }
}

//create main function to call all necessary functions and control flow of actions
int main() {
    //create variables which call the appropriate functions to retrieve and store the base and the exponent
    float base = getBase();
    int exp = getExp();
    //if the base is less than 0, ask the user to try again and call main method again
    if (base < 0) {
        printf("The base entered must be a positive number! Try again.\n");
        main();
    }
    //if base is positive than call the recursive calculation function
    else {
        //create variable to store the answer
        float answr = doCalc(base, exp);
        //check if exponent is negative, if yes then divide 1 by the answer
        if (exp < 0) {
            answr = 1 / answr;
        }
    //print out the answer to the user
    printf("%0.02f raised to the power of %d is %0.003f!\n", base, exp, answr);
    }
    return 0;
}
