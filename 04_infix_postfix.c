/* Experiment 4: Infix to postfix conversion and postfix evaluation
   Operators: + - * / ^ and parentheses.
   Operands: single letters/digits (use digits for evaluation). */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 100

char opStack[MAX];
int top = -1;

void push(char c) { opStack[++top] = c; }
char pop() { return opStack[top--]; }
char peek() { return opStack[top]; }

int prec(char c) {
    switch (c) {
    case '^': return 3;
    case '*': case '/': return 2;
    case '+': case '-': return 1;
    }
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char c;
    top = -1;
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];
        if (isalnum(c))
            postfix[k++] = c;
        else if (c == '(')
            push(c);
        else if (c == ')') {
            while (top != -1 && peek() != '(') postfix[k++] = pop();
            if (top != -1) pop();           /* discard '(' */
        } else if (c != ' ') {
            /* '^' is right associative, others left associative */
            while (top != -1 && peek() != '(' &&
                   (prec(peek()) > prec(c) ||
                    (prec(peek()) == prec(c) && c != '^')))
                postfix[k++] = pop();
            push(c);
        }
    }
    while (top != -1) postfix[k++] = pop();
    postfix[k] = '\0';
}

int evaluate(char postfix[]) {
    int st[MAX], t = -1, i, a, b;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c))
            st[++t] = c - '0';
        else {
            b = st[t--];
            a = st[t--];
            switch (c) {
            case '+': st[++t] = a + b; break;
            case '-': st[++t] = a - b; break;
            case '*': st[++t] = a * b; break;
            case '/': st[++t] = a / b; break;
            case '^': st[++t] = (int)pow(a, b); break;
            }
        }
    }
    return st[t];
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, numeric = 1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    for (i = 0; postfix[i]; i++)
        if (isalpha(postfix[i])) numeric = 0;

    if (numeric)
        printf("Result of evaluation: %d\n", evaluate(postfix));
    else
        printf("Expression has variables; evaluation skipped (use single digits to evaluate).\n");
    return 0;
}
