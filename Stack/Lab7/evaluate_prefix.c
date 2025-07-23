//44. Write a program for evaluation of prefix Expression using Stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int performOpr(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Division by zero error\n");
                exit(1);
            }
            return a / b;
        case '^': return (int)pow(a, b);
        default:
            printf("Invalid operator: %c\n", op);
            exit(1);
    }
}

void reverseTokens(char str[]) {
    int len = strlen(str);
    char temp[MAX];
    int i = len - 1, j = 0;

    while (i >= 0) {
        while (i >= 0 && isspace(str[i])) i--;  // Skip spaces

        int end = i;
        while (i >= 0 && !isspace(str[i])) i--;

        int start = i + 1;
        for (int k = start; k <= end; k++) {
            temp[j++] = str[k];
        }
        if (j < MAX - 1) temp[j++] = ' ';
    }

    if (j > 0) j--; // Remove last space
    temp[j] = '\0';
    strcpy(str, temp);
}

int evaluatePrefix(char expr[]) {
    reverseTokens(expr);

    int i = 0, k = 0;
    char token[20];

    while (1) {
        while (isspace(expr[i])) i++;
        if (expr[i] == '\0') break;

        k = 0;
        while (expr[i] != ' ' && expr[i] != '\0') {
            token[k++] = expr[i++];
        }
        token[k] = '\0';

        if (strlen(token) == 1 && isOperator(token[0])) {
            int val1 = pop();
            int val2 = pop();
            int res = performOpr(val1, val2, token[0]);
            push(res);
        } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(atoi(token));
        } else {
            printf("Invalid token: %s\n", token);
            exit(1);
        }
    }

    if (top != 0) {
        printf("ERROR: Invalid prefix expression\n");
        exit(1);
    }

    return pop();
}

int main() {
    char prefix[MAX];
    printf("Enter prefix expression (space-separated): ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strcspn(prefix, "\n")] = '\0'; // Remove trailing newline

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n", result);

    return 0;
}