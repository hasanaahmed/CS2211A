//
//  task1.c
//  CS2211Lab7
//
//  Created by Hasan Ahmed on 2018-10-29.
//

#include <stdio.h>

int sum_array(const int *a, int size)
{
    int i, sum = 0;
    for ( i = 0; i < size; i++)
        sum += *(a+i);
    return sum;
}

int main() {
    int a[] = {3, 5, 7, 9};
    int results = sum_array(a, 4);
    printf("%d\n", results);
}
