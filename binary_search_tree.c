// BINARY SEARCH TREE IMPLEMENTATION USING DYNAMIC MEMORY ALLOCATION
#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define NULL 0

struct bst_node
{
    int data;
    struct bst_node *left;
    struct bst_node *right;
};

struct bst_node *root_ptr = NULL;

int insert_node(int val)
{
    struct bst_node *temp = (struct bst_node*)malloc(sizeof(struct bst_node)), *parent;
    temp->data = val;
    temp->right = temp->left = NULL;
    parent = root_ptr;
    if(root_ptr == NULL)
    {
        root_ptr = temp;
    }
    else
    {
        struct bst_node *current;
        current = root_ptr;
        while(current)
        {
            parent = current;
            if(temp->data > current->data)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        if(temp->data>parent->data)
        {
            parent->right = temp;
        }
        else
        {
            parent->left = temp;
        }
    }
    return FALSE;
}

int delete_node(int val)
{
    struct bst_node *current, *parent;
    current = root_ptr;
    while(current->data != val)
    {
        parent = current;
        if(val > current->data)
        {
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }
    if(current->left == NULL && current->right == NULL)
    {
        if(parent->data > current->data)
        {
            parent->left = NULL;
            free(current);
        }
        else
        {
            parent->right = NULL;
            free(current);
        }
    }
    else if(current->left == NULL || current->right == NULL)
    {
        if(current->left != NULL)
        {
            if(parent->data > current->data)
            {
                parent->left = current->left;
                current->left = NULL;
                free(current);
            }
            else
            {
                parent->right = current->left;
                current->left = NULL;
                free(current);
            }

        }
        else
        {
            if((parent->data > current->data))
            {
                parent->left = current->right;
                current->right = NULL;
                free(current);
            }
            else
            {
                parent->right = current->right;
                current->right = NULL;
                free(current);
            }
        }
    }
    else
    {
        struct bst_node *temp, *temp_parent;
        temp = current->left;
        if(temp->right == NULL)
        {
            current->data = temp->data;
            current->left = NULL;
            free(temp);
        }
        else
        {
            while(temp->right != NULL)
            {
            temp_parent = temp;
            temp = temp->right;
            }
            current->data = temp_parent->right->data;
            temp_parent->right = NULL;
            free(temp);
        }
    }
    return FALSE;
}

int inorder(struct bst_node* pr) // pr => pseudo root node
{
    if(pr->left)
    {
        inorder(pr->left);
    }
    printf(" %d",pr->data);
    if(pr->right)
    {
        inorder(pr->right);
    }
}

int preorder(struct bst_node* pr)
{
    if(pr == NULL) return;
    printf(" %d",pr->data);
    preorder(pr->left);
    preorder(pr->right);
}

int postorder(struct bst_node* pr) // pr => pseudo root node
{
    if(pr->right)
    {
        postorder(pr->right);
    }
    printf(" %d",pr->data);
    if(pr->left)
    {
        postorder(pr->left);
    }
}

int main()
{
    struct bst_node * pseudo_root;
    insert_node(50);
    insert_node(25);
    insert_node(12);
    insert_node(100);
    insert_node(37);
    insert_node(17);
    insert_node(6);
    insert_node(75);
    insert_node(88);
    insert_node(200);
    insert_node(150);
    insert_node(300);
    insert_node(60);
    insert_node(350);
    insert_node(192);
    insert_node(325);
    insert_node(375);
    insert_node(170);
    insert_node(193);
    pseudo_root = root_ptr;
    printf("\n\nPreorder Representation of all the node in the tree: \n");preorder(pseudo_root);
    printf("\n\nPostorder Representation of all the node in the tree: \n");postorder(pseudo_root);
    printf("\n\nIn-order Representation of all the node in the tree: \n");inorder(pseudo_root);
    printf("\n\nDeleting Node 12:");delete_node(12);
    printf("\n\nIn-order Representation of all the node in the tree: \n");inorder(pseudo_root);
    printf("\n\nDeleting Node 150:");delete_node(150);
    printf("\n\nIn-order Representation of all the node in the tree: \n");inorder(pseudo_root);
    printf("\n\nDeleting Node 6:");delete_node(6);
    printf("\n\nIn-order Representation of all the node in the tree: \n");inorder(pseudo_root);
    return FALSE;
}
