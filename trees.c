#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* llink;
    struct node* rlink;
} node;

// Function to create a new node
node* createnode(int data) {
    node* new = (node*)malloc(sizeof(node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->data = data;
    new->llink = NULL;
    new->rlink = NULL;
    return new;
}

// Recursive function to create a binary tree
node* bt() {
    int data;
    printf("Enter data or -1 to stop:\n");
    scanf("%d", &data);

    // Base case: if input is -1, return NULL for no node
    if (data == -1) {
        printf("No node created\n");
        return NULL;
    }

    // Create the root node for this subtree
    node* root = createnode(data);
    printf("Node created with data %d\n", data);

    // Recursively create left and right children
    printf("Enter Left child of %d:\n", data);
    root->llink = bt();

    printf("Enter Right child of %d:\n", data);
    root->rlink = bt();

    return root;
}

// Function to print the binary tree in in-order traversal
void print(node* root) {
    if (root == NULL) return;

    // Visit the left subtree
    print(root->llink);

    // Print the data of the node
    printf("%d ", root->data);

    // Visit the right subtree
    print(root->rlink);
}

// Main function
int main() {
    node* root = NULL;

    printf("Create the binary tree:\n");
    root = bt();

    printf("\nIn-order Traversal:\n");
    print(root);
    printf("\n");

    return 0;
}
