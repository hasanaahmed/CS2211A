//
//  bst.h
//  cs2211asn4
//
//  Created by Hasan Ahmed on 2018-11-14.
//
//include required header files
#ifndef bst_h
#define bst_h

#include "data.h"

typedef struct {Node *tree_nodes; unsigned char *is_free; int size;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, int data);
int bstree_insert_node(BStree bst, Key *key, int data, int a);
void bstree_traversal(BStree bst);
void bstree_traversal_inorder(BStree bst, int index);
void bstree_free(BStree bst);

#endif /* bst_h */

