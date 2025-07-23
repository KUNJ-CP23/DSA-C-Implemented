//43. Write a program for evaluation of postfix Expression using Stack

#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluatePostfix(char expr[]) {
    char c;
    int i = 0;

    while ((c = expr[i++]) != '\0') {
        if (isspace(c)) continue;

        if (isdigit(c)) {
            push(c - '0');  // convert char digit to int
        } else {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero error\n");
                        return -1;
                    }
                    push(val1 / val2); 
                    break;
                case '^': push((int)pow(val1, val2)); break;
                default:
                    printf("Invalid operator: %c\n", c);
                    return -1;
            }
        }
    }

    return pop();
}

int main() {
    char postfix[MAX];
    printf("Enter postfix expression (single-digit operands, no spaces): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}