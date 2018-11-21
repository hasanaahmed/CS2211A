//
//  pi.c
//  cs2211asn4
//
//  Created by Hasan Ahmed on 2018-11-14.
//
//include appropriate headers required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//define main function
int main (void) {
    //initialize required variables
    long double precision;
    long double pi_part = 0;
    long double pi = 0;
    int count = 1;
    long double den = 0.000;
    long double num = 0.000;
    
    //ask the user for their degree of precision required
    printf("State the smallest precision you would like: ");
    //scan in input
    scanf("%Lf", &precision);
    //relay precision back for accuracy
    printf("Precision: %.10Lf\n", precision);
    
    //do while loop for calculation
    do {
        //formula calculation to calculate Pi
        if (count % 2 == 1) {
            pi_part = (long double) ((long double) (4) / (long double) (2 * count - 1));
            count ++;
            pi = pi + pi_part;
        }
        else {
            pi_part = (long double) ((long double) (4) / (long double) (2 * count - 1));
            count++;
            pi -= pi_part;
        }
    } while (fabsl(pi_part) > precision);
    
    //relay answer to user
    printf("The approx. value of pi is: %.10Lf \n", pi);
    
    //exit program safetly 
    return 0;
}
