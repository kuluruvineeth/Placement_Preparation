#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}no;

no* newNode(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int depth(no* root)
{
    if(root==NULL) return INT_MAX;
    if(root->left==NULL && root->right==NULL) return 1;
    return 1 + min(depth(root->left),depth(root->right)); 
}

int minDepth(no* root)
{
    if(root==NULL) return 0;
    else if(root->left==NULL && root->right==NULL) return 1;
    return depth(root);
}

int main()
{
    no* root = newNode(1);
    root->left = newNode(2);
    cout<<minDepth(root)<<endl;
    return 0;
}