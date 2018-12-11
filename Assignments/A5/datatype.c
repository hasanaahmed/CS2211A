//
//  datatype.c
//  cs2211asn5
//
//  Created by Hasan Ahmed on 2018-11-27.
//
#include "datatype.h"

//Duplicate string pointed to by str with dynamic memory allocation.
char * string_dup(char *str) {
    //initialize
    char *strDup;
    //check if null
    if ((strDup = malloc(strlen(str)*sizeof(char))) == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    //copy string and return
    strcpy(strDup,str);
    return strDup;
}

//Generate a key with dynamic memory allocation.
Key key_gen(char *skey1, char *skey2) {
    //initialize
    Key newKey;
    newKey = malloc(sizeof(Key_struct));
    //set keys
    newKey -> skey1 = string_dup(skey1);
    newKey -> skey2 = string_dup(skey2);
    //return newKey
    return newKey;
}

//Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then
//they determine the comparison result. If key1->skey1 and key2->skey1 are the same,
//then key1->skey2 and key2->skey2 determine the comparison result
int key_comp(Key key1, Key key2) {
    //compare keys
    if (strcmp(key1 -> skey1, key2 -> skey1) != 0) {
        //return comparison
        return strcmp(key1 -> skey1, key2 -> skey1);
    }
    else {
        //return comparison
        return strcmp(key1 -> skey2, key2 -> skey2);
    }
}

//Print a key.
void key_print(Key key) {
    //print keys
    printf("%-15s",key -> skey1);
    printf("%-15s", key -> skey2);
}

//Free memory allocated for key.
void key_free(Key key) {
    free(key -> skey1);
    free(key -> skey2);
    free(key);
}

//Generate a data with dynamic memory allocation.
Data data_gen(int idata) {
    //initialize
    Data data = (int*) malloc(sizeof(int)*idata);
    *data = idata;
    //return data
    return data;
}

//Assign data with idata.
void data_set(Data data, int idata) {
    *data = idata;
}

//Print a data.
void data_print(Data data) {
    printf("%-15d\n", *data);
}

//Free memory allocated for data.
void data_free(Data data) {
    free(data);
}
