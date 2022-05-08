#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
}no;

void print(no *root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

//Function to find the minimum element in BST
int minValue(no *root)
{
    if(root==NULL) return -1;
    no *curr = root;
    while(curr->left!=NULL) curr=curr->left;
    return(curr->data);
}

//function to find maximum element in BST
int maxValue(no *root)
{
    if(root==NULL) return -1;
    no *curr = root;
    while(curr->right!=NULL) curr=curr->right;
    return curr->data;
}

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    print(root);
    cout<<"max value is : "<<maxValue(root)<<endl;
    cout<<"min value is : "<<minValue(root)<<endl;
    return 0;
}