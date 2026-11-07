/* Experiment 5: Linear queue using array */
#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) { printf("Queue Overflow\n"); return; }
    if (front == -1) front = 0;
    q[++rear] = x;
    printf("%d inserted\n", x);
}

void dequeue() {
    if (front == -1 || front > rear) { printf("Queue Underflow\n"); return; }
    printf("%d deleted\n", q[front++]);
    if (front > rear) front = rear = -1;   /* queue became empty: reset */
}

void display() {
    int i;
    if (front == -1) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
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
