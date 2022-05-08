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

//this function finds predecessor and successor of key in BST.
//it sets pre and suc as predecessor and successor respectively.
void findPreSuc(no *root,no*& pre,no*& suc,int key)
{
    //base case
    if(root==NULL) return;
    //if key is present at root
    if(root->data==key)
    {
        //the maximum value in left subtree is predecessor
        if(root->left!=NULL)
        {
            no *temp = root->left;
            while(temp->right!=NULL) temp = temp->right;
            pre = temp;
        }
        // the minimum value in right subtree is successor
        if(root->right!=NULL)
        {
            no *temp = root->right;
            while(temp->left!=NULL) temp=temp->left;
            suc = temp;
        }
        return;
    }
    //if key is smaller than root's key, go to left subtree
    if(root->data>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
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
    inorderTraversal(root);
    no *pre = NULL,*suc = NULL;
    findPreSuc(root,pre,suc,10);
    if(pre!=NULL) cout<<"Predecessor is : "<<pre->data<<endl;
    else cout<<"No predeccesor"<<endl;
    if(suc!=NULL) cout<<"Successor is : "<<suc->data<<endl;
    else cout<<"No Successor"<<endl;
    return 0;
}