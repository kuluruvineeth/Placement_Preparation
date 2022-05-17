#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct node* removeHalfNodes(struct node* root)
{
    if(!root) return NULL;
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);

    if(root->left==NULL && root->right==NULL) return root;

    /*if current nodes is a half node with left child NULL,
    then it's right child is returned and replaces it in the given tree*/
    if(root->left==NULL)
    {
        struct node* new_root = root->right;
        free(root);
        return new_root;
    }
    /*if current nodes is a half node with right child NULL,
    then its left child is returned and replaces it in the given tree*/
    if(root->right==NULL)
    {
        struct node* new_root = root->left;
        free(root);
        return new_root;
    }
    return root;
}

void printInorder(struct node* root)
{
    if(root!=NULL)
    {
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}
    
int main()
{
    struct node* root =  newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);

    cout<<"Inorder traversal of given tree"<<" ";
    printInorder(root);
    struct node* newRoot = removeHalfNodes(root);

    cout<<"Inorder traversal of modified tree"<<" ";
    printInorder(newRoot);
    return 0;

}