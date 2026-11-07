/* Experiment 7: Double-ended queue (deque) using a circular array */
#include <stdio.h>
#define MAX 5

int dq[MAX], front = -1, rear = -1, count = 0;

void insertFront(int x) {
    if (count == MAX) { printf("Deque Overflow\n"); return; }
    if (count == 0) front = rear = 0;
    else front = (front - 1 + MAX) % MAX;
    dq[front] = x;
    count++;
    printf("%d inserted at front\n", x);
}

void insertRear(int x) {
    if (count == MAX) { printf("Deque Overflow\n"); return; }
    if (count == 0) front = rear = 0;
    else rear = (rear + 1) % MAX;
    dq[rear] = x;
    count++;
    printf("%d inserted at rear\n", x);
}

void deleteFront() {
    if (count == 0) { printf("Deque Underflow\n"); return; }
    printf("%d deleted from front\n", dq[front]);
    front = (front + 1) % MAX;
    if (--count == 0) front = rear = -1;
}

void deleteRear() {
    if (count == 0) { printf("Deque Underflow\n"); return; }
    printf("%d deleted from rear\n", dq[rear]);
    rear = (rear - 1 + MAX) % MAX;
    if (--count == 0) front = rear = -1;
}

void display() {
    int i, idx;
    if (count == 0) { printf("Deque is empty\n"); return; }
    printf("Deque (front to rear): ");
    for (i = 0; i < count; i++) {
        idx = (front + i) % MAX;
        printf("%d ", dq[idx]);
    }
    printf("\n");
}

int main() {
    int ch, x;
    do {
        printf("\n1.Insert Front 2.Insert Rear 3.Delete Front 4.Delete Rear 5.Display 6.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: printf("Enter value: "); scanf("%d", &x); insertFront(x); break;
        case 2: printf("Enter value: "); scanf("%d", &x); insertRear(x); break;
        case 3: deleteFront(); break;
        case 4: deleteRear(); break;
        case 5: display(); break;
        }
    } while (ch != 6);
    return 0;
}
