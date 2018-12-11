//
//  main.c
//  cs2211asn5
//
//  Created by Hasan Ahmed on 2018-11-27.
//

#include "matrix.h"

void stdinInput(Matrix agentSmith);

//main method to run
int main(void) {
    
    //welcome statement
    printf("Welcome to Hasan's Matrix\n");
    
    //create a new matrix.
    Matrix mat = matrix_construction();
    
    //read from stdin, or redirect from a file,
    stdinInput(mat);
    
    //print the data in the Matrix
    matrix_list(mat);
    printf("\n");
    
    //free all allocated memory spaces for the Matrix and terminate.
    matrix_destruction(mat);
    
    return 0;
}


//User input for tree:
//take in and insert pairs of strings and integers, in the order they
//are read, insert them into the Matrix and calculate occurences
void stdinInput(Matrix matrix) {
    int elements;
    char str1[1000], str2[1000];
    
    //user instructions
    printf("Enter items in the exact order: 'ITEM 1' 'ITEM 2'\n");
    printf("Without the quotes, and WITH a space between ITEM 1 and ITEM 2.\n");
    
    printf("\n    Hit 'CTRL-D' then ENTER/RETURN to quit.\n");
    //get elements and insert into the tree
    while ((elements = scanf(" %s %s", str1, str2)) == 2) {
        matrix_set(matrix, str1, str2, 1);
    }
    
    printf("\n");
}

