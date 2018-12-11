//
//  matrix.h
//  cs2211asn5
//
//  Created by Hasan Ahmed on 2018-11-27.
//

#ifndef matrix_h
#define matrix_h

//include header files
#include "bstree.h"

//define
typedef BStree Matrix;
typedef char* Index;
typedef int Value;

Matrix matrix_construction(void);
unsigned char matrix_isin(Matrix m, Index index1, Index index2);
Value *matrix_get(Matrix m, Index index1, Index index2);
void matrix_set(Matrix m, Index index1, Index index2, Value value);
void matrix_inc(Matrix m, Index index1, Index index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);

#endif /* matrix_h */
