#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int checkBalanced(node* root)
{
    if(root==NULL) return 1;
    else if(root->left==NULL && root->right==NULL) return 1;
    else if(root->left!=NULL && root->right!=NULL)
    {
        return min(checkBalanced(root->right),checkBalanced(root->left));
    }
    else if(root->left==NULL)
    {
        if(root->right!=NULL)
        {
            node* temp = root->right;
            if(temp->right!=NULL || temp->left!=NULL) return 0;
        }
        return 1;
    }
    else if(root->right==NULL)
    {
        if(root->left!=NULL)
        {
            node* temp = root->left;
            if(temp->right!=NULL || temp->left!=NULL) return 0;
        }
        return 1;
    }
    return 1;
}

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    //root->left->right = newNode(3);
    cout<<checkBalanced(root)<<endl;
    return 0;
}