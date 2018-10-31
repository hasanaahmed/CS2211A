//
//  part1.c
//  Lab5
//
//  Created by Hasan Ahmed on 2018-10-16.
//

#include "part1.h"
#include <math.h>
int main () {
    int xval;
    printf("Enter a value for x: ");
    scanf("%d", &xval);
    int ans = (3 * pow(xval, 5)) + (2 * pow(xval, 4)) - (5 * pow(xval, 3)) - pow(xval, 2) + (7 * xval) - 6;
    printf("The answer is: %d\n", ans);
    return 0;
}
