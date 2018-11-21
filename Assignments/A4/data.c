//
//  data.c
//  cs2211asn4
//
//  Created by Hasan Ahmed on 2018-11-14.
//
//include required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

//define ket_construct function
Key *key_construct(char *in_name, int in_id) {
    //allocate memory properly
    Key *key = (Key *) malloc(sizeof(Key));
    //store key name
    key -> name = strdup(in_name);
    //store key id
    key -> id = in_id;
    //return key
    return key;
}

//define key_comp function
int key_comp(Key key1, Key key2) {
    //see the difference between the two keys
    int variance = strcmp(key1.name, key2.name);
    //if they have the same name do further analysis
    if (variance == 0) {
        //if id is also same, return 0
        if (key1.id == key2.id) {
            return 0;
        }
        //if key2 has a larger id then return -1
        else if (key1.id < key2.id) {
            return - 1;
        }
        //if key1 has a larger id then return 1
        else if (key1.id > key2.id) {
            return 1;
        }
    }
    //if variance is greater than 0, return 1
    else if (variance > 0) {
        return 1;
        
    }
    //if variance is smaller than 0, return -1
    else if (variance < 0) {
        return -1;
    }
    //exit function
    return 0;
}

//function to print the key name and id
void print_key(Key *key) {
    printf("(\%-12s%d)", key -> name, key -> id);
}

//function to print the node data along with print_key function
void print_node(Node node) {
    print_key(node.key);
    printf("      %d\n", node.data);
}
