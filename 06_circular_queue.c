/* Experiment 6: Circular queue using array */
#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

int isFull()  { return (rear + 1) % MAX == front; }
int isEmpty() { return front == -1; }

void enqueue(int x) {
    if (isFull()) { printf("Queue Overflow\n"); return; }
    if (isEmpty()) front = rear = 0;
    else rear = (rear + 1) % MAX;
    q[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue() {
    if (isEmpty()) { printf("Queue Underflow\n"); return; }
    printf("%d deleted\n", q[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    int i;
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (i = front; i != rear; i = (i + 1) % MAX) printf("%d ", q[i]);
    printf("%d\n", q[rear]);
}

int main() {
    int ch, x;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: printf("Enter value: "); scanf("%d", &x); enqueue(x); break;
        case 2: dequeue(); break;
        case 3: display(); break;
        }
    } while (ch != 4);
    return 0;
}
