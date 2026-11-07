/* Experiment 6: Circular queue insertion and deletion using arrays */
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }
    if (front == -1 && rear == -1)
        front = rear = 0;
    else if (rear == MAX - 1 && front != 0)
        rear = 0;
    else
        rear = rear + 1;
    queue[rear] = val;
}

void delete() {
    int val;
    if (front == -1) {
        printf("Underflow\n");
        return;
    }
    val = queue[front];
    printf("Deleted element: %d\n", val);
    if (front == rear)
        front = rear = -1;
    else if (front == MAX - 1)
        front = 0;
    else
        front = front + 1;
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    int choice, val;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
