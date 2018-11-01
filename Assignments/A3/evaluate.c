//
//  evaluate.c
//  function: to evaluate simple arithmetic expressions
//  range: all expressions evaluated using +, -, *, and/or /
//  CS2211Asn3
//
//  Created by Hasan Ahmed on 2018-10-24.
//

#include "stdio.h"
#include "stdlib.h"

//function to retrieve the next float number in the stdin
float get_num() {
    //initialize the float variable float to store the next number in
    float num;
    //scan the next float in and store it in the variable num
    scanf("%f", &num);
    //return the next number to where it was called from
    return num;
}

//function to get the next operator from the stdin
char get_op() {
    //intialize and store the next operator in the char variable op
    char op = getc(stdin);
    //if statement to make sure the operator stored is valid
    if (op == '*' || op == '/' || op == '\n' || op == '+' || op == '-') {
        //return the operator back to where it was called from
        return op;
    }
    // setup a do-while to keep getting the next character until it not a blank space
    else if (op == ' ') {
        do {
            op = getc(stdin);
        }
        while (op == ' ');
        //return the operator back to where it was called from
        return op;
    }
    //catch user typing 'no' and call exit
    else if (op == 'n' || op == 'N') {
        char next_op = getc(stdin);
        if (next_op == 'o' || op == 'O') {
            exit(EXIT_FAILURE);
        }
        else {
            return 0;
        }
    }
    //catch any illegal characters and tell the user
    else {
        printf("You entered the following illegal operator: %c", op);
        return 0;
    }
}

//function to do multiplication and division
float m_exp(float sub_exp, char op) {
    //check to see if the operator is the end of the line
    if (op == '\n') {
        //send the character back to stdin
        ungetc('\n', stdin);
        //return the subexpression
        return sub_exp;
    }
    //check to see if the operator is a plus sign
    else if (op == '+') {
        //send it back to stdin
        ungetc('+', stdin);
        //return the subexpression
        return sub_exp;
    }
    //check to see if the operator is a negative sign
    else if (op == '-') {
        //send it back to stdin
        ungetc('-', stdin);
        //return the subexpression
        return sub_exp;
    }
    //else statement if the operator is a valid * or /
    else {
        //get the next number after operator
        float next_num = get_num();
        //get the next operator after evaluation
        char next_op = get_op();
        //if the operator is a * sign then multiple
        if (op == '*') {
            next_num = sub_exp * next_num;
        }
        //since else statement, divide the floats to get answer
        else {
            next_num = sub_exp / next_num;
        }
        //return calling the function again with new number and next operator
        return m_exp(next_num, next_op);
    }
}

//function to do higher level processing, addition, and substraction
float s_exp(float float_num, char op) {
    //get the subexpression until the end of the line or +/-
    float right_side = m_exp(float_num, op);
    //get the next operator after the current one
    char next_op = get_op();
    //if the next operator is the end of the line, return subexpression
    if (next_op == '\n') {
        return right_side;
    }
    //get the next number following the operator (+/-)
    float left_side = get_num();
    //if next operator is + then do addition and store the following operator
    if (next_op == '+') {
        char post_op = get_op();
        left_side = m_exp(left_side, post_op);
        right_side = right_side + left_side;
    }
    //if next operator is a - then do subtraction and store the following operator
    else if (next_op == '-') {
        char post_op = get_op();
        left_side = m_exp(left_side, post_op);
        right_side = right_side - left_side;
    }
    //else return the subexpression
    else {
        return right_side;
    }
    //get the next operator to call the s_exp again
    char final_op = get_op();
    //call s_exp again recursively
    return s_exp(right_side, final_op);
}

//main function to run evaluate.c
int main() {
    //intialize the floats num to store the number, and results to store the answer
    float num, results;
    //intialize the char op to store the operator
    char op;
    //ask user to input an expression to evaluate
    printf("Enter a simple arithmetic expression: ");
    //call get_num() to get the next number and store it in num
    num = get_num();
    //call get_op() to get the next operator and store it in op
    op = get_op();
    //call s_exp(num, op) to start evaluating the expression and storing the answer in results
    results = s_exp(num, op);
    //print the answer stored in results to the user
    printf("The answer is %0.02f\n", results);
    //exit the program successfully 
    return 0;
}
