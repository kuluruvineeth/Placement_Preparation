#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    // store the old value
    int old_val = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);

    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return root->data + old_val;

}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    toSumTree(root);
    cout<<"Inorder traversal of sum tree : ";
    inorder(root);
    return 0;
}