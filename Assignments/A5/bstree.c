//
//  bstree.c
//  cs2211asn5
//
//  Created by Hasan Ahmed on 2018-11-27.
//

#include "bstree.h"

//Allocate memory of type BStree node*, set the value to NULL, and return a pointer to the
//allocated memory.
BStree bstree_ini(void) {
    //initialize
    BStree tree;
    //allocate memory
    tree = (BStree) malloc(sizeof(BStree_node*));
    *tree = NULL;
    return tree;
}

//Insert data with key into bst. If key is in bst, then do nothing.
//You may want to use a helper function for insertion to create a pointer to a tree node from
//key and data.
void bstree_insert(BStree bst, Key key, Data data) {
    //if bst is empty, add new node
    if (*bst == NULL) {
        *bst = new_node(key, data);
    }
    //check tree
    else {
        bst_insert(*bst, key, data);
    }
}

//helper method
static void bst_insert(BStree_node *node, Key key, Data data) {
    //key comparison greater than 0
    if (key_comp(key, node -> key) > 0) {
        if (node -> left == NULL) {
            //assign new node
            node -> left = new_node(key, data);
        }
        //seach rest of tree
        else {
            bst_insert(node -> left, key, data);
        }
    }
    //if key comparison less than 0
    else if (key_comp(key, node -> key) < 0) {
        if (node -> right == NULL) {
            //assign new node
            node -> right = new_node(key, data);
        }
        //search rest of tree
        else {
            bst_insert(node -> right, key, data);
        }
    }
}

//helper method
BStree_node *new_node(Key key, Data data) {
    //initialize and allocate
    BStree_node *node;
    node = (BStree_node*)malloc(sizeof(BStree_node));
    
    //set new nodes
    node -> key = key;
    node -> data = data;
    
    node -> left = NULL;
    node -> right = NULL;
    
    //return node
    return node;
}

//If key is in bst, return key’s associated data. If key is not in bst, return NULL.
Data bstree_search(BStree bst, Key key) {
    //if bst is not empty
    if (*bst != NULL) {
        //run key comparison
        int cmp = key_comp(key, (*bst) -> key);
        //if comparison less than 0
        if (cmp < 0) {
            bstree_search(&(*bst) -> left, key);
        }
        //if comparison greater than 0
        else if (0 < cmp) {
            bstree_search(&(*bst) -> right, key);
        }
        //if comparison is equal to 0
        else if (cmp == 0){
            return (*bst)  -> data;
        }
    }
    return NULL;
}

//helper method
static Data *bst_search(BStree_node *node, Key key){
    //if node is null
    if (node == NULL) {
        return NULL;
    }
    //if comparison is equal to 0
    else if (key_comp(key, node->key) == 0) {
        return &node -> data;
    }
    //if comparison is less than 0
    else if (key_comp(node->key, key) < 0) {
        return bst_search(node -> left, key);
    }
    //if comparison is greater than 0
    else if (key_comp(node -> key, key) > 0) {
        return bst_search(node -> right, key);
    }
    return 0;
}

//In order traversal of bst and print each node’s key and data.
void bstree_traversal(BStree bst) {
    inOrder(*bst);
}

//helper method
static void inOrder(BStree_node *node) {
    //if node is not null
    if (node != NULL) {
        //set accordingly
        inOrder(node -> right);
        key_print(node -> key);
        data_print(node -> data);
        inOrder(node -> left);
    }
}

//Free all the dynamically allocated memory of bst.
void bstree_free(BStree bst) {
    bst_free(*bst);
    free(bst);
}

//helper method
static void bst_free(BStree_node *node) {
    if(node == NULL) {
        return;
    }
    bst_free(node -> left);
    bst_free(node -> right);
    free(node);
}
