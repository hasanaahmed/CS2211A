//
//  task2.c
//  CS2211Lab7
//
//  Created by Hasan Ahmed on 2018-10-29.
//

#include <stdio.h>

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int i, j, sum = 0;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < LEN; j++)
            sum += a[i][j];
    return sum;
}
