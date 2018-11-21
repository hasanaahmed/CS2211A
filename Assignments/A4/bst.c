//
//  bst.c
//  cs2211asn4
//
//  Created by Hasan Ahmed on 2018-11-14.
//
//include required header files
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//define function bstree_ini
BStree bstree_ini(int size) {
    //allocate memory accordingly
    BStree bst = (BStree_struct*) malloc(sizeof(BStree_struct));
    //create variable to access size
    bst -> size = size;
    //allocate memory for nodes
    bst -> tree_nodes = (Node*) malloc(sizeof(Node)*(size + 1));
    //allocate memory for is_free
    bst -> is_free = (unsigned char *) malloc(sizeof(unsigned char)*(size + 1));
    //loop to set all nodes to free before any insertions
    int i;
    for (i = 0; i < size; i++) {
        bst -> is_free[i] = 1;
    }
    //return binary search tree
    return bst;
}

//define function bstree_insert which will insert the nodes accordingly
void bstree_insert(BStree bst, Key *key, int data) {
    //set index to one initially
    int a = 1;
    //call function to do managing
    bstree_insert_node(bst, key, data, a);
}

//define bstree_insert_node which does the hard coding for the logic in inserting the node in the right spot
int bstree_insert_node(BStree bst, Key *key, int data, int a) {
    //if index is greater than size, give AOB error
    if (a > bst -> size) {
        printf("Array out of bound error\n");
        //return a
        return a;
    }
    //is the location is free insert in current index
    else if (bst -> is_free[a] == 1){
        Node node = {key, data};
        bst -> tree_nodes[a] = node;
        //set node to taken
        bst -> is_free[a] = 0;
        //return a
        return a;
    }
    //if the index location is taken, do analysis of where to go
    else if (bst ->is_free[a] != 1) {
        //compare the keys
        int val = key_comp(*key, *((*bst).tree_nodes[a].key));
        //variance value dictates the side to follow
        if (val > 0) {
            a = (a * 2) + 1;
            //insert node
            bstree_insert_node(bst, key, data, a);
        }
        else if (val < 0) {
            a = a * 2;
            //insert node
            bstree_insert_node(bst, key, data, a);
        }
        //could not be entered due to duplication
        else {
            return -1;
        }
    }
    //exit function properly
    return 0;
}

//define function bstree_transversal to start reading tree properly
void bstree_traversal(BStree bst) {
    //call helper function
    bstree_traversal_inorder(bst, 1);
}

//define function bstree_transversal_inorder to do proper in order analysis to print accordingly
void bstree_traversal_inorder(BStree bst, int index){
    if (bst -> is_free[index] == 0) {
        //check condition to call function again
        if (bst -> size >= (index * 2) && bst->is_free[index * 2] == 0) {
            //call function again
            bstree_traversal_inorder(bst, index * 2);
        }
        //print the node by calling print function
        print_node(bst -> tree_nodes[index]);
        //check condition to call function again
        if (bst -> size >= (index * 2 + 1) && bst -> is_free[(index * 2 + 1)] == 0) {
            //call function again
            bstree_traversal_inorder(bst, (index * 2 + 1));
        }
    }
}

//define function bstree_free to free memory that was being allocated 
void bstree_free(BStree bst) {
    free(bst -> tree_nodes);
    free(bst -> is_free);
    free(bst);
}
