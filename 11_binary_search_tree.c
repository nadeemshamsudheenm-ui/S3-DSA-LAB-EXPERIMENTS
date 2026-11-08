/* Experiment 11: Binary search tree and its operations */
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

/* Step 3: allocate and initialise a new node */
struct node *createNode(int value) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/* Step 4: insert */
struct node *insert(struct node *t, int value) {
    if (t == NULL)
        return createNode(value);
    if (value < t->data)
        t->left = insert(t->left, value);
    else if (value > t->data)
        t->right = insert(t->right, value);
    else
        printf("%d already exists, not inserted\n", value);
    return t;
}

/* Step 5: search */
struct node *search(struct node *t, int value) {
    if (t == NULL)
        return NULL;
    if (t->data == value)
        return t;
    if (value < t->data)
        return search(t->left, value);
    return search(t->right, value);
}

/* Step 6: delete */
struct node *deleteNode(struct node *t, int value) {
    struct node *temp, *succ;
    if (t == NULL) {
        printf("%d not found in the tree\n", value);
        return NULL;
    }
    if (value < t->data)
        t->left = deleteNode(t->left, value);
    else if (value > t->data)
        t->right = deleteNode(t->right, value);
    else {
        if (t->left == NULL && t->right == NULL) {      /* no children */
            free(t);
            return NULL;
        }
        if (t->left == NULL) {                          /* only right child */
            temp = t->right;
            free(t);
            return temp;
        }
        if (t->right == NULL) {                         /* only left child */
            temp = t->left;
            free(t);
            return temp;
        }
        succ = t->right;                                /* two children: in-order successor */
        while (succ->left != NULL)
            succ = succ->left;
        t->data = succ->data;                           /* replace value with successor's */
        t->right = deleteNode(t->right, succ->data);    /* delete the successor */
    }
    return t;
}

/* Step 7: in-order */
void inorder(struct node *t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}

/* Step 8: pre-order */
void preorder(struct node *t) {
    if (t != NULL) {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

/* Step 9: post-order */
void postorder(struct node *t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}

int main() {
    int choice, value;
    do {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Inorder traversal\n");
        printf("5. Preorder traversal\n6. Postorder traversal\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter the value to search: ");
            scanf("%d", &value);
            if (search(root, value) != NULL)
                printf("%d is found in the tree\n", value);
            else
                printf("%d is not found in the tree\n", value);
            break;
        case 3:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 4:
            if (root == NULL) printf("Tree is empty\n");
            else { printf("Inorder: "); inorder(root); printf("\n"); }
            break;
        case 5:
            if (root == NULL) printf("Tree is empty\n");
            else { printf("Preorder: "); preorder(root); printf("\n"); }
            break;
        case 6:
            if (root == NULL) printf("Tree is empty\n");
            else { printf("Postorder: "); postorder(root); printf("\n"); }
            break;
        case 7: break;
        default: printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}
