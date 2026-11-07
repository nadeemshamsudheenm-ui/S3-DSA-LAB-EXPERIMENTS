/* Experiment 3: Implementation of stack using an array */
#include <stdio.h>
#define MAX 5

int top = -1;                       /* top = -1 means stack is empty */

void push(int stack[], int value) {
    if (top == MAX - 1)
        printf("STACK OVERFLOW\n");
    else {
        top++;
        stack[top] = value;
    }
}

int pop(int stack[]) {
    int val;
    if (top == -1) {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
    val = stack[top];
    top--;
    return val;
}

void display(int stack[]) {
    int i;
    if (top == -1)
        printf("STACK IS EMPTY\n");
    else {
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[MAX], option, value, val;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            val = pop(stack);
            if (val != -1)
                printf("Popped element: %d\n", val);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (option != 4);

    return 0;
}
