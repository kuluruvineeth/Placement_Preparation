#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data=d;
        left = right = NULL;
    }
}no;

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//returns true if the given tree is BST and its values are >=min and <=max
int isBSTUtil(no *root,int min,int max)
{
    if(root==NULL) return 1;

    //false if this node violates the min/max constraint
    if(root->data < min || root->data > max) return 0;

    //otherwise check the subtrees recursively tightening the min or max constraint
    return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}
//returns true if the given tree is bst
int isBST(no *root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main()
{
    no *root = new node(5);
    root->right = new node(12);
    root->right->left = new node(2);
    cout<<isBST(root)<<endl;
    return 0;
}
