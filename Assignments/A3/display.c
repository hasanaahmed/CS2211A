//
//  display.c
//  function: takes in the integer from user input and displays it in seven-segment display
//  range: all integers
//  CS2211Asn3
//
//  Created by Hasan Ahmed on 2018-10-28.
//

#include "stdio.h"
#include "stdlib.h"

//create the main function to be called
int main() {
    //intitalize the 3d array segments which will store all the numbers in seven-segment display format
    const char segments[11][3][3] = {
        //segemnt for 0
        {
            {' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}
        },
        //segment for 1
        {
            {' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}
        },
        //segment for 2
        {
            {' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}
        },
        //segment for 3
        {
            {' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}
        },
        //segment for 4
        {
            {' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}
        },
        //segment for 5
        {
            {' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}
        },
        //segment for 6
        {
            {' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}
        },
        //segment for 7
        {
            {' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}
        },
        //segment for 8
        {
            {' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}
        },
        //segment for 9
        {
            {' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}
        },
        //segment for '-'
        {
            {' ', ' ', ' '}, {' ', '_', ' '}, {' ', ' ', ' '}
        }
    };
    //create int variable num_in to store the number the user wants to print
    int num_in;
    char term;
    
    //ask the user to input a valid integer to print out
    printf("Enter an integer you wish to be displayed: ");
    
    //scan input and store the integer to print out in variable num_in if valid
    if (scanf("%d%c", &num_in, &term) != 2 || term != '\n') {
        //check to see if integer was inputted
        printf("You entered an invalid input!\n");
        exit(EXIT_FAILURE);
    }
    
    //run the program with valid input
    else {
        //setup variables needed to modify the numbers to parse
        int modify = 0, a = 10, b = 0;
        int middle, number_used;
        
        //procedure if the number is positive
        if (num_in >= 0) {
            //used to determine the number of digits in the integer
            while((modify%a) != num_in) {
                modify = num_in % a;
                a = a * 10;
                //length of integer is stored in b
                b++;
            }
            //parse through first loop which is the 3 rows in each segment
            for (int i = 0; i < 3; i++) {
                //evaluate middle to be used in calculating number for later
                for (int j = 0; j < b; j++) {
                    middle = num_in;
                    //parse through and determine middle to use to get number_used
                    for (int k = 0; k < (b - j - 1); k++) {
                        middle = middle / 10;
                    }
                    number_used = middle % 10;
                    //print segments
                    for (int l = 0; l < 3; l++) {
                        printf("%c", segments[number_used][i][l]);
                    }
                }
                //push each new row down to next line
                printf("\n");
            }
        }
        //procedure if the number is negative
        else if (num_in < 0) {
            //convert to a positive integer to determine absolute value
            int num_pos = num_in * -1;
            //used to determine the number of digits in the integer
            while((modify%a) != num_pos) {
                modify = num_pos % a;
                a = a * 10;
                //length of integer is stored in b
                b++;
            }
            char neg[1][3][3];
            for (int h = 0; h < 3; h++){
                for (int g = 0; g < 3; g++) {
                    neg[0][h][g] = segments[10][h][g];
                }
            }
            
            char numbers[b+1][3][3];
            //parse through first loop which is the 3 rows in each segment
            for (int i = 0; i < 3; i++) {
                //evaluate middle to be used in calculating number for later
                for (int j = 0; j < b + 1; j++) {
                    middle = num_pos;
                    //parse through and determine middle to use to get number_used
                    for (int k = 0; k < (b - j - 1); k++) {
                        middle = middle / 10;
                    }
                    number_used = middle % 10;
                    //print segments
                    for (int l = 0; l < 3; l++) {
                        numbers[j+1][i][l] = segments[number_used][i][l];
                        //print negative for first segment
                        if (j == 0) {
                            printf("%c", neg[j][i][l]);
                        }
                        //print the numbers for all other segments
                        else {

                            printf("%c", numbers[j][i][l]);
                        }
                    }
                }
                //push each new row down to next line
                printf("\n");
            }
        }
    }
    //set up character to track if user wants to continue
    char cont;
    
    //ask user if they wish to continue
    printf("Do you want to continue? (Y/N): ");
    
    //scan in the response and store it in char variable cont
    scanf(" %c", &cont);
    
    //if user replied with yes, then call main function
    if (cont == 'Y' | cont == 'y') {
        main();
    }
    
    //if user replied with no, then exit
    else if (cont == 'N'  || cont == 'n') {
        printf("Exiting!\n");
        return 0;
    }
    
    //user replied with an invalid key, exit
    else {
        printf("Not a valid reply, exiting.\n");
        return 0;
    }
    
    //exit properly
    return 0;
}
