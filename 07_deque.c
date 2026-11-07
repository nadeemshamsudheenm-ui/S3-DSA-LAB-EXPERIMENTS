/* Experiment 7: Input restricted and output restricted double-ended queue */
#include <stdio.h>
#define Size 5

int deque_arr[Size];
int front = -1, rear = -1;

void insert_rear(int item) {
    if ((front == 0 && rear == Size - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (rear == Size - 1)
        rear = 0;
    else
        rear = rear + 1;
    deque_arr[rear] = item;
}

void insert_front(int item) {
    if ((front == 0 && rear == Size - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
        front = Size - 1;
    else
        front = front - 1;
    deque_arr[front] = item;
}

void delete_front() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from front: %d\n", deque_arr[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (front == Size - 1)
        front = 0;
    else
        front = front + 1;
}

void delete_rear() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from rear: %d\n", deque_arr[rear]);
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
        rear = Size - 1;
    else
        rear = rear - 1;
}

void display_queue() {
    int i;
    if (front == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements: ");
    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("%d ", deque_arr[i]);
    }
    else {
        for (i = front; i <= Size - 1; i++)
            printf("%d ", deque_arr[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", deque_arr[i]);
    }
    printf("\n");
}

void input_que() {
    int choice, item;
    do {
        printf("\n1. Insert at rear\n2. Delete from front\n3. Delete from rear\n4. Display\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &item);
            insert_rear(item);
            break;
        case 2: delete_front(); break;
        case 3: delete_rear(); break;
        case 4: display_queue(); break;
        case 5: break;
        default: printf("Wrong choice\n");
        }
    } while (choice != 5);
}

void output_que() {
    int choice, item;
    do {
        printf("\n1. Insert at rear\n2. Insert at front\n3. Delete from front\n4. Display\n5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &item);
            insert_rear(item);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &item);
            insert_front(item);
            break;
        case 3: delete_front(); break;
        case 4: display_queue(); break;
        case 5: break;
        default: printf("Wrong choice\n");
        }
    } while (choice != 5);
}

int main() {
    int choice;
    printf("1. Input Restricted Deque\n2. Output Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1)
        input_que();
    else if (choice == 2)
        output_que();
    else
        printf("Wrong choice\n");
    return 0;
}
