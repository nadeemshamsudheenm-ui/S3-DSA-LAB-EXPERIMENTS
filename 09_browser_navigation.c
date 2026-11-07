/* Experiment 9: Back/forward navigation of visited web pages
   using a doubly linked list */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct page {
    char url[100];
    struct page *prev, *next;
};
struct page *current = NULL;

/* Visit a new page: everything ahead of the current page is discarded */
void visit(char url[]) {
    struct page *p = (struct page *)malloc(sizeof(struct page));
    struct page *t, *tmp;
    strcpy(p->url, url);
    p->prev = p->next = NULL;

    if (current != NULL) {
        t = current->next;
        while (t) {                 /* clear forward history */
            tmp = t;
            t = t->next;
            free(tmp);
        }
        current->next = p;
        p->prev = current;
    }
    current = p;
    printf("Visited: %s\n", current->url);
}

void back() {
    if (current == NULL || current->prev == NULL) {
        printf("No previous page\n");
        return;
    }
    current = current->prev;
    printf("Back to: %s\n", current->url);
}

void forward() {
    if (current == NULL || current->next == NULL) {
        printf("No next page\n");
        return;
    }
    current = current->next;
    printf("Forward to: %s\n", current->url);
}

void showHistory() {
    struct page *t = current;
    if (!current) { printf("No history\n"); return; }
    while (t->prev) t = t->prev;    /* go to oldest page */
    printf("History: ");
    while (t) {
        if (t == current) printf("[%s]", t->url);
        else printf("%s", t->url);
        if (t->next) printf(" <-> ");
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch;
    char url[100];
    do {
        printf("\n1.Visit new page 2.Back 3.Forward 4.Show history 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: printf("Enter URL: "); scanf("%s", url); visit(url); break;
        case 2: back(); break;
        case 3: forward(); break;
        case 4: showHistory(); break;
        }
    } while (ch != 5);
    return 0;
}
