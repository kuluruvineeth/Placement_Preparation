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
vector<no*> v;
void inorder(no *root,vector<no*> &v)
{
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}

no *solve(int start,int end)
{
    if(start>end) return NULL;
    int mid = (start+end)/2;
    no *root = v[mid];
    root->left = solve(start,mid-1);
    root->right = solve(mid+1,end);
    return root;
}
void print(no *root)
{
    if(!root) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    no *root = new node(10);
    root->left = new node(8);
    root->left->left= new node(7);
    root->left->left->left = new node(6);
    root->left->left->left->left = new node(5);
    inorder(root,v);
    root = solve(0,v.size()-1);
    print(root);
}




