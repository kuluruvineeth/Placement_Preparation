#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}no;

// Helper function that
// allocates a new node with the
// given data and NULL left and right pointers
no* createNode(int val)
{
    no* newNode = (no*)malloc(sizeof(no));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to print the inorder traversal
void inorder(no* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

//Function to convert to mirror tree
no* mirrorTree(no* root)
{
    if(root==NULL)
    {
        return root;
    }
    no* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left)
    {
        mirrorTree(root->left);
    }
    if(root->right)
    {
        mirrorTree(root->right);
    }
    return root;
}

int main()
{
    no* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
    cout<<"Inorder traversal of original tree : ";
    inorder(tree);
    mirrorTree(tree);
    cout<<"Inorder traversal of mirror tree : ";
    inorder(tree);
    return 0;
}
