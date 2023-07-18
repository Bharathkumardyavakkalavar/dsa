#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct AVLNode
{
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
};
struct AVLNode * deletenode(struct AVLNode * root,int data);
 struct AVLNode  *minValueNode(  struct AVLNode  *node);
int height(struct AVLNode* node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct AVLNode* newNode(int data)
{
    struct AVLNode* node = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode* rightRotate(struct AVLNode* y)
{
    struct AVLNode* x = y->left;
    struct AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct AVLNode* leftRotate(struct AVLNode* x)
{
    struct AVLNode* y = x->right;
    struct AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;

    return y;
}
int getBalance(struct AVLNode* node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
struct AVLNode* insert(struct AVLNode* node, int data)
{
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

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(struct AVLNode* root,FILE *fp2)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        fprintf(fp2,"%d ", root->data);
        preorder(root->left,fp2);
        preorder(root->right,fp2);
    }
}
void inorder(struct AVLNode* root,FILE *fp2)
{
    if (root != NULL)
    {
        inorder(root->left,fp2);
        printf("%d ", root->data);
        fprintf(fp2,"%d ", root->data);
        inorder(root->right,fp2);
    }
}
void postorder(struct AVLNode* root,FILE *fp2)
{
    if (root != NULL)
    {
        postorder(root->left,fp2);
        postorder(root->right,fp2);
        printf("%d ", root->data);
       fprintf(fp2,"%d ", root->data);
    }
}
int isPerfectlyBalanced(struct AVLNode* node)
{
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

int main()
{
    clock_t start,end;
    double total;
    FILE* fp1 = fopen("input.txt", "w");
    FILE* fp2 = fopen("input1.txt", "w");
    srand(time(NULL));
    struct AVLNode* root = NULL;
    int data;
    int i, num;
    int random_nums[100];

    start=clock();
    scanf("%d",&num);
     for (i = 0; i < num; i++)
     {
        random_nums[i] = rand() % 100;
        printf("%d ", random_nums[i]);
        fprintf(fp1," %d ", random_nums[i]);
        root=insert(root, random_nums[i]);
     }
                printf("\n");
                fprintf(fp2,"\n post-Order traversal: ");
                printf("Preorder traversal of the AVL tree: ");
                preorder(root,fp2);
                printf("\n");
                fprintf(fp2,"\n In-Order traversal: ");
                printf("inorder traversal of the AVL tree: ");
                inorder(root,fp2);
                printf("\n");
                fprintf(fp2,"\n post-Order traversal: ");
                printf("Postorder traversal of the AVL tree: ");
                postorder(root,fp2);
                printf("\n");
                if (isPerfectlyBalanced(root))
                {
                    printf("The AVL tree is a perfect balanced tree.\n");
                }
                else
                {
                    printf("The AVL tree is not a perfect balanced tree.\n");
                }
                int key;
                printf("enter the node to be deleted\n");
                scanf("%d",&key);
                deletenode(root,key);
                printf("\n");
                fprintf(fp2,"\n In-Order traversal after deleting: ");
                printf("inorder traversal of the AVL tree after deleting: ");
                inorder(root,fp2);
                printf("\n");
                fprintf(fp2,"\n post-Order traversal after deleting: ");
                printf("Preorder traversal of the AVL tree after deleting: ");
                preorder(root,fp2);
                printf("\n");
                fprintf(fp2,"\n post-Order traversal after deleting:  ");
                printf("Postorder traversal of the AVL tree after deleting: ");
                postorder(root,fp2);
                end= clock();
     total= (double)(end-start)/CLOCKS_PER_SEC;
      fprintf(fp2," time %f",total);




}
struct AVLNode * deletenode(struct AVLNode * root,int data)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if ( data< root->data )
        root->left = deletenode(root->left, data);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if( data > root->data )
        root->right = deletenode(root->right, data);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct AVLNode  *temp = root->left ? root->left :
                                             root->right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {// One child case
             *root =  *temp; // Copy the contents of
                            // the non-empty child
            free(temp);
            }
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct AVLNode * temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->data= temp->data;

            // Delete the inorder successor
            root->right = deletenode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


struct AVLNode  *minValueNode(  struct AVLNode  *node)
   {
    struct AVLNode  *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}


