#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};

int height(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct AVLNode* newNode(int data) {
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* rightRotate(struct AVLNode* y) {
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct AVLNode* leftRotate(struct AVLNode* x) {
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}



int getBalance(struct AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct AVLNode* insert(struct AVLNode* node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}







void preOrder(struct AVLNode* root, FILE* outputFile) {
    if (root != NULL) {
        fprintf(outputFile, "%d ", root->data);
        preOrder(root->left, outputFile);
        preOrder(root->right, outputFile);
    }
}

int isPerfectlyBalanced(struct AVLNode* node) {
    if (node == NULL)
        return 1;

    if (node->left == NULL && node->right == NULL)
        return 1;

    if (node->left == NULL || node->right == NULL)
        return 0;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight != rightHeight)
        return 0;

    return isPerfectlyBalanced(node->left) && isPerfectlyBalanced(node->right);
}

int main() {
    struct AVLNode* root = NULL;
    int choice, data;

    // Open input and output files
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open files.\n");
        return 1;
    }

    while (1) {
        // Read choice from the input file
        fscanf(inputFile, "%d", &choice);

        switch (choice) {
            case 1:

                fscanf(inputFile, "%d", &data);
                root = insert(root, data);
               fprintf(outputFile, "inserted successfully.\n");
                break;
            case 2:
                     fprintf(outputFile, "Preorder traversal of the AVL tree: ");
                     preOrder(root, outputFile);
                     fprintf(outputFile, "\n");
                      break;

            case 3:
                if (getBalance(root))
                    fprintf(outputFile, "The AVL tree is a  balanced tree.\n");
                else
                    fprintf(outputFile, "The AVL tree is not a  balanced tree.\n");
                break;





            case 4:
                if (isPerfectlyBalanced(root))
                    fprintf(outputFile, "The AVL tree is a perfectly balanced tree.\n");
                else
                    fprintf(outputFile, "The AVL tree is not a perfectly balanced tree.\n");
                break;








            case 5:
                fprintf(outputFile, "Exiting the program.\n");
                fclose(inputFile);
                fclose(outputFile);
                return 0;
            default:
                fprintf(outputFile, "Invalid choice. Please try again.\n");
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
