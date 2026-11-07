/* Experiment 8: Various operations on a singly linked list */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertBegin(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int value) {
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (head == NULL) {                 /* empty list */
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insertPos(int value, int pos) {
    struct node *newnode, *temp;
    int i;
    if (pos == 1) {                     /* no node before position 1 */
        insertBegin(value);
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;              /* node just before the position */
    if (temp == NULL || pos < 1) {
        printf("Invalid position\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBegin() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void deleteEnd() {
    struct node *temp, *last;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {           /* only one node */
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;              /* second-to-last node */
    last = temp->next;
    temp->next = NULL;
    printf("Deleted element: %d\n", last->data);
    free(last);
}

void deletePos(int pos) {
    struct node *temp, *del;
    int i;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {                     /* no node before position 1 */
        deleteBegin();
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;              /* node just before the position */
    if (temp == NULL || temp->next == NULL || pos < 1) {
        printf("Invalid position\n");
        return;
    }
    del = temp->next;
    temp->next = del->next;
    printf("Deleted element: %d\n", del->data);
    free(del);
}

struct node *search(int value) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value, pos;
    struct node *p;
    do {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete first node\n5. Delete last node\n6. Delete at position\n");
        printf("7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &value);
            insertBegin(value);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        case 3:
            printf("Enter the value and position: ");
            scanf("%d %d", &value, &pos);
            insertPos(value, pos);
            break;
        case 4: deleteBegin(); break;
        case 5: deleteEnd(); break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &pos);
            deletePos(pos);
            break;
        case 7:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            p = search(value);
            if (p != NULL)
                printf("%d is found in the list\n", p->data);
            else
                printf("%d is not found in the list\n", value);
            break;
        case 8: display(); break;
        case 9: break;
        default: printf("Invalid choice\n");
        }
    } while (choice != 9);
    return 0;
}
