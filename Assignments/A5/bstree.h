//
//  bstree.h
//  cs2211asn5
//
//  Created by Hasan Ahmed on 2018-11-27.
//
#ifndef bstree_h
#define bstree_h

//include header file
#include "datatype.h"

//define
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node** BStree;

BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
BStree_node *new_node(Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traversal(BStree bt);
void bstree_free(BStree bst);

static void bst_insert(BStree_node *node, Key key, Data data);
static Data *bst_search(BStree_node *node, Key key);
static void inOrder(BStree_node *node);
static void bst_free(BStree_node *bst);

#endif /* bstree_h */
