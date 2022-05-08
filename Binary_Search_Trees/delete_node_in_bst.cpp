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

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
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

no* deleteNode(no *root,int key)
{
    //base case
    if(!root) return NULL;

    //if value of root matches with the key
    if(root->data == key)
    {
        //if there is not right child then simply attach root's parent with root's child
        if(!root->right)
        {
            no *left = root->left;
            delete root;
            return left;
        }
        //if there is no left child then simply attach root's parent with root's child
        else if(!root->left)
        {
            no *right = root->right;
            delete root;
            return right;
        }
        //then swap with right-subtrees smallest child with curr-value,also BST wont change
        //alternative way we can also swap left-subtrees greatest child with curr-value,still BST wont change
        else
        {
            no *right = root->right;
            while(right->left)
            {
                right = right->left;
            }
            swap(root->data,right->data);
        }
    }
    //get deleted and arranged from the recursion
    root->left = deleteNode(root->left,key);
    root->right = deleteNode(root->right,key);
    return root;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    insert(root,217);
    inorderTraversal(root);
    no *root1 = deleteNode(root,12);
    inorderTraversal(root1);
    return 0;
}