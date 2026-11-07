/* Experiment 9: Back and forward navigation of visited web pages
   using a doubly linked list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
};

struct Node *current = NULL;

void visitPage() {
    struct Node *newnode, *temp, *del;
    char url[100];

    printf("Enter the URL: ");
    scanf("%s", url);

    newnode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newnode->url, url);
    newnode->prev = NULL;
    newnode->next = NULL;

    if (current != NULL) {
        temp = current->next;               /* clear forward history */
        while (temp != NULL) {
            del = temp;
            temp = temp->next;
            free(del);
        }
        current->next = newnode;            /* link new node after current */
        newnode->prev = current;
    }
    current = newnode;
    printf("Visited page: %s\n", current->url);
}

void goBack() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        printf("Moved back to: %s\n", current->url);
    }
    else
        printf("No previous page!\n");
}

void goForward() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        printf("Moved forward to: %s\n", current->url);
    }
    else
        printf("No forward page!\n");
}

void showCurrent() {
    if (current != NULL)
        printf("Current page: %s\n", current->url);
    else
        printf("No page visited yet!\n");
}

int main() {
    int choice;
    do {
        printf("\n1. Visit Page\n2. Back\n3. Forward\n4. Show Current Page\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: visitPage(); break;
        case 2: goBack(); break;
        case 3: goForward(); break;
        case 4: showCurrent(); break;
        case 5: break;
        default: printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
