//
//  part3.c
//  Lab5
//
//  Created by Hasan Ahmed on 2018-10-16.
//

#include "part3.h"

int main() {
    int num, reverse = 0, remain;
    printf("Enter a 3-digit number: ");
    scanf("%d", &num);
    while (num != 0){
        remain = num % 10;
        reverse = reverse * 10 + remain;
        num /= 10;
    }
    printf("The reversal is: %d\n", reverse);
    return 0;
}
