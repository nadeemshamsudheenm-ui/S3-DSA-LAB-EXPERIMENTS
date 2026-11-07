/* Experiment 5: Implementation of queue using an array */
#include <stdio.h>
#define MAX 5

int q[MAX + 1];                 /* positions 1 to MAX are used */
int front = 0, rear = 0;

void create() {
    char ch;
    front = 1;
    do {
        if (rear == MAX) {
            printf("Queue is full\n");
            break;
        }
        rear++;
        printf("Enter the element: ");
        scanf("%d", &q[rear]);
        printf("Do you want to continue (Y/N)? ");
        scanf(" %c", &ch);
    } while (ch != 'N' && ch != 'n');
}

void traverse() {
    int i;
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}

void insert() {
    int m;
    if (rear == MAX) {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &m);
    rear++;
    q[rear] = m;
}

void delete() {
    if (front > rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted element: %d\n", q[front]);
    q[front] = '\0';
    front++;
    if (front > rear) {         /* queue became empty: reset */
        front = 1;
        rear = 0;
    }
}

int main() {
    create();
    traverse();
    insert();
    traverse();
    delete();
    traverse();
    return 0;
}
