//
//  matrix.c
//  cs2211asn5
//
//  Created by Hasan Ahmed on 2018-11-27.
//
#include "matrix.h"

//Matrix construction using bstree ini();
Matrix matrix_construction(void) {
    Matrix matrix = bstree_ini();
    //return marix
    return matrix;
    
}

//If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
unsigned char matrix_isin(Matrix m, Index index1, Index index2) {
    if (bstree_search(m, key_gen(index1, index2)) != NULL) {
        //location is defined
        return 1;
    }
    else {
        //location is not defined
        return 0;
    }
}

//If location (index1, index2) is defined in Matrix m, then return a pointer to the associated value. Otherwise, return NULL.
Value *matrix_get(Matrix m, Index index1, Index index2) {
    //initialize
    Key key;
    Data getData;
    
    //generate key
    key = key_gen(index1, index2);
    //get data
    getData = bstree_search(m, key);
    
    //if data is null
    if (getData == NULL) {
        return NULL;
    }
    //if data is not null
    else {
        return getData;
    }
}

//Assign value to Matrix m at location (index1, index2). If that location already has value,
//then overwrite.
void matrix_set(Matrix m, Index index1, Index index2, Value value) {
    //get matrix
    Value *itemToCheck = matrix_get(m, index1, index2);
    //check if null
    if (itemToCheck == NULL) {
        //insert
        Key key = key_gen(index1, index2);
        bstree_insert(m, key, data_gen(value));
    }
    else {
        (*itemToCheck) ++;
    }
}

//If location (index1, index2) is defined in Matrix m, then increase the associated value by
//value. Otherwise, report error.
void matrix_inc(Matrix m, Index index1, Index index2, Value value) {
    //initialize
    Key key;
    Value *currentData;
    
    //generate key and set current data
    key = key_gen(index1, index2);
    currentData = bstree_search(m, key);
    
    //set matrix
    if (currentData != NULL) {
        matrix_set(m, index1, index2, *currentData + value);
    }
    //report error
    printf("ERROR");
}

//Print indices and values in the Matrix m (with bstree traversal()).
void matrix_list(Matrix m) {
    printf("%-12s   %-12s   %-12s\n", "String 1",   "String 2",   "Occurrence");
    //call transversal
    bstree_traversal(m);
}

//Free allocated space (with bstree free()).
void matrix_destruction(Matrix m) {
    bstree_free(m);
}
