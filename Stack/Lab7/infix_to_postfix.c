//infix_to_postfix 41. Write a program to convert infix notation to postfix notation using stack.

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int validateInfix(char expr[]) {
    int open = 0; //open bracket counter
    int expectOperand = 1;

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (isspace(c)) continue;

        if (isalnum(c)) {
            if (!expectOperand) return 0;
            expectOperand = 0;
        } else if (c == '(') {
            open++;
            expectOperand = 1;
        } else if (c == ')') {
            open--;
            if (open < 0 || expectOperand) return 0;
            expectOperand = 0;
        } else if (isOperator(c)) {
            if (expectOperand) return 0;
            expectOperand = 1;
        } else {
            return 0;
        }
    }

    return (open == 0 && !expectOperand);
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char c;
    top = -1;

    while ((c = infix[i++]) != '\0') {
        if (isspace(c)) continue;

        if (isalnum(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(')
                postfix[j++] = pop();
            if (peek() == '(')
                pop();
        }
        else {
            while (top != -1 && precedence(peek()) > precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression (no spaces): ");
    scanf("%s", infix);

    if (!validateInfix(infix)) {
        printf("Invalid infix expression!\n");
        return 1;
    }

    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n", postfix);

    return 0;
}