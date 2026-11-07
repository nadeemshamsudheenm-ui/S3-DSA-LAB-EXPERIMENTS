/* Experiment 8: Operations on a singly linked list */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *newNode(int x) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = NULL;
    return n;
}

void insertBegin(int x) {
    struct node *n = newNode(x);
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    struct node *n = newNode(x), *t = head;
    if (head == NULL) { head = n; return; }
    while (t->next) t = t->next;
    t->next = n;
}

void insertPos(int x, int pos) {
    struct node *n, *t = head;
    int i;
    if (pos == 1) { insertBegin(x); return; }
    for (i = 1; i < pos - 1 && t; i++) t = t->next;
    if (t == NULL) { printf("Invalid position\n"); return; }
    n = newNode(x);
    n->next = t->next;
    t->next = n;
}

void deleteBegin() {
    struct node *t = head;
    if (!head) { printf("List is empty\n"); return; }
    head = head->next;
    printf("%d deleted\n", t->data);
    free(t);
}

void deleteEnd() {
    struct node *t = head, *prev = NULL;
    if (!head) { printf("List is empty\n"); return; }
    while (t->next) { prev = t; t = t->next; }
    if (prev) prev->next = NULL; else head = NULL;
    printf("%d deleted\n", t->data);
    free(t);
}

void deleteValue(int x) {
    struct node *t = head, *prev = NULL;
    while (t && t->data != x) { prev = t; t = t->next; }
    if (!t) { printf("%d not found\n", x); return; }
    if (prev) prev->next = t->next; else head = t->next;
    free(t);
    printf("%d deleted\n", x);
}

void search(int x) {
    struct node *t = head;
    int pos = 1;
    while (t) {
        if (t->data == x) { printf("%d found at position %d\n", x, pos); return; }
        t = t->next; pos++;
    }
    printf("%d not found\n", x);
}

void reverse() {
    struct node *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

int count() {
    int c = 0;
    struct node *t = head;
    while (t) { c++; t = t->next; }
    return c;
}

void display() {
    struct node *t = head;
    if (!head) { printf("List is empty\n"); return; }
    while (t) { printf("%d -> ", t->data); t = t->next; }
    printf("NULL\n");
}

int main() {
    int ch, x, pos;
    do {
        printf("\n1.Insert at beginning  2.Insert at end  3.Insert at position\n"
               "4.Delete from beginning 5.Delete from end 6.Delete by value\n"
               "7.Search 8.Reverse 9.Count 10.Display 11.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: printf("Value: "); scanf("%d", &x); insertBegin(x); break;
        case 2: printf("Value: "); scanf("%d", &x); insertEnd(x); break;
        case 3: printf("Value and position: "); scanf("%d %d", &x, &pos); insertPos(x, pos); break;
        case 4: deleteBegin(); break;
        case 5: deleteEnd(); break;
        case 6: printf("Value: "); scanf("%d", &x); deleteValue(x); break;
        case 7: printf("Value: "); scanf("%d", &x); search(x); break;
        case 8: reverse(); printf("List reversed\n"); break;
        case 9: printf("Number of nodes: %d\n", count()); break;
        case 10: display(); break;
        }
    } while (ch != 11);
    return 0;
}
