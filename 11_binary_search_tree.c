/* Experiment 11: Binary Search Tree and its operations */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int x) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

struct node *insert(struct node *root, int x) {
    if (root == NULL) return newNode(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    else printf("Duplicate %d ignored\n", x);
    return root;
}

struct node *findMin(struct node *root) {
    while (root && root->left) root = root->left;
    return root;
}

struct node *findMax(struct node *root) {
    while (root && root->right) root = root->right;
    return root;
}

struct node *deleteNode(struct node *root, int x) {
    struct node *t;
    if (root == NULL) { printf("%d not found\n", x); return NULL; }
    if (x < root->data) root->left = deleteNode(root->left, x);
    else if (x > root->data) root->right = deleteNode(root->right, x);
    else {
        if (root->left == NULL) {           /* 0 or 1 child (right) */
            t = root->right;
            free(root);
            return t;
        }
        if (root->right == NULL) {          /* 1 child (left) */
            t = root->left;
            free(root);
            return t;
        }
        t = findMin(root->right);           /* 2 children: inorder successor */
        root->data = t->data;
        root->right = deleteNode(root->right, t->data);
    }
    return root;
}

struct node *search(struct node *root, int x) {
    if (root == NULL || root->data == x) return root;
    if (x < root->data) return search(root->left, x);
    return search(root->right, x);
}

void inorder(struct node *r)   { if (r) { inorder(r->left);  printf("%d ", r->data); inorder(r->right); } }
void preorder(struct node *r)  { if (r) { printf("%d ", r->data); preorder(r->left); preorder(r->right); } }
void postorder(struct node *r) { if (r) { postorder(r->left); postorder(r->right); printf("%d ", r->data); } }

int height(struct node *r) {
    int l, h;
    if (r == NULL) return -1;
    l = height(r->left);
    h = height(r->right);
    return (l > h ? l : h) + 1;
}

int countNodes(struct node *r) {
    return r ? 1 + countNodes(r->left) + countNodes(r->right) : 0;
}

int main() {
    struct node *root = NULL, *t;
    int ch, x;
    do {
        printf("\n1.Insert 2.Delete 3.Search 4.Inorder 5.Preorder 6.Postorder\n"
               "7.Min 8.Max 9.Height 10.Count nodes 11.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: printf("Value: "); scanf("%d", &x); root = insert(root, x); break;
        case 2: printf("Value: "); scanf("%d", &x); root = deleteNode(root, x); break;
        case 3: printf("Value: "); scanf("%d", &x);
                printf(search(root, x) ? "%d found\n" : "%d not found\n", x); break;
        case 4: printf("Inorder: ");   inorder(root);   printf("\n"); break;
        case 5: printf("Preorder: ");  preorder(root);  printf("\n"); break;
        case 6: printf("Postorder: "); postorder(root); printf("\n"); break;
        case 7: t = findMin(root);
                if (t) printf("Minimum: %d\n", t->data); else printf("Tree is empty\n"); break;
        case 8: t = findMax(root);
                if (t) printf("Maximum: %d\n", t->data); else printf("Tree is empty\n"); break;
        case 9: printf("Height: %d\n", height(root)); break;
        case 10: printf("Nodes: %d\n", countNodes(root)); break;
        }
    } while (ch != 11);
    return 0;
}
