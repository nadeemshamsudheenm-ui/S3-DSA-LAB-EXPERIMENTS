/* Experiment 4: Infix to postfix conversion and evaluation of postfix expression */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[30];
int top = -1;

void push(char symbol) {
    if (top >= 29) {
        printf("Stack is overflow\n");
        return;
    }
    top++;
    stack[top] = symbol;
}

char pop() {
    char i;
    if (top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    i = stack[top];
    top--;
    return i;
}

int prec(char c) {
    switch (c) {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    default:  return 0;            /* '(' has the lowest precedence */
    }
}

void infix_to_postfix(char infix[], char postfix[]) {
    int length, index = 0, pos = 0;
    char symbol, temp;

    length = strlen(infix);
    while (index < length) {
        symbol = infix[index];
        switch (symbol) {
        case '(':
            push(symbol);
            break;
        case ')':
            temp = pop();
            while (temp != '(') {          /* '(' is removed, not appended */
                postfix[pos++] = temp;
                temp = pop();
            }
            break;
        case '^':
        case '+':
        case '-':
        case '*':
        case '/':
            while (top != -1 && prec(stack[top]) >= prec(symbol)) {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symbol);
            break;
        default:                           /* operand */
            postfix[pos++] = symbol;
        }
        index++;
    }
    while (top != -1) {
        temp = pop();
        postfix[pos++] = temp;
    }
    postfix[pos] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

/* ---------- Evaluation of postfix expression ---------- */
int evalStack[30];
int evalTop = -1;

void evalPush(int x) {
    evalTop++;
    evalStack[evalTop] = x;
}

int evalPop() {
    if (evalTop == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    return evalStack[evalTop--];
}

int evaluate(char postfix[]) {
    int i, op1, op2, result, k;
    char ch;

    evalTop = -1;                              /* empty stack */
    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            evalPush(ch - '0');                /* convert char to integer */
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            op2 = evalPop();                   /* first popped  */
            op1 = evalPop();                   /* second popped */
            switch (ch) {
            case '+': result = op1 + op2; break;
            case '-': result = op1 - op2; break;
            case '*': result = op1 * op2; break;
            case '/': result = op1 / op2; break;
            case '^':
                result = 1;
                for (k = 0; k < op2; k++)
                    result = result * op1;
                break;
            }
            evalPush(result);
        }
        /* space or any other character is ignored */
    }
    return evalStack[evalTop];                 /* final result */
}

int main() {
    char infix[50], postfix[50];

    printf("Enter a valid infix expression (single-digit numbers to evaluate): ");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("Result of evaluation: %d\n", evaluate(postfix));
    return 0;
}
