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
/*
    iterative solution
    TC: O(H), H is the height of the tree
*/
no* lca(no *root,int n1,int n2)
{
    while(root!=NULL)
    {
        //if both n1 and n2 are smaller than root,then lca lies in left
        if(root->data > n1 && root->data > n2) root = root->left;
        //if both n1 and n2 are greater than root, then lca lies in right
        else if(root->data < n1 && root->data < n2) root= root->right;
        else break;
    }
    return root;
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
    no *root1 = lca(root,10,12);
    cout<<"Least common ancestor of 10 and 12 is : "<<root1->data<<endl;
    return 0;
}