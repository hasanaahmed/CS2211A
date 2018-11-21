//
//  main.c
//  cs2211asn4
//
//  Created by Hasan Ahmed on 2018-11-15.
//
//include required header files
#include <stdio.h>
#include "bst.h"

//define main function
int main(void) {
    //initialize variables required
    FILE *fp;
    char txtFile[32];
    int r, id, data;
    char word[32];
    //create binary search tree
    BStree bst;
    bst = bstree_ini(65);
    //ask user for file of objects to insert
    printf("Enter the name of the file to read in (include.txt): ");
    //scan in input
    scanf("%s", txtFile);
    //open the .txt file
    fp = fopen(txtFile, "r");
    //if file does not exist, exit and print error
    if (fp == NULL) {
        printf("Error opening file\n");
        return -1;
    }
    //if file does exist, read in line by line
    else {
        //while loop for line not reaching the bottom of file
        while (r != EOF) {
            //scan in the word, id, and data from the line
            r = fscanf(fp, "%s%d%d", word, &id, &data);
            //insert the variables in to the binary search tree
            bstree_insert(bst, key_construct(word, id), data);
        }
        //close file when end is reached
        fclose(fp);
        //operate a transversal on the binary search tree
        bstree_traversal(bst);
        //free memory before ending
        bstree_free(bst);
    }
    //exit program safetly 
    return 0;
}
