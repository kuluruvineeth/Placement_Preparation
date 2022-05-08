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
        left=right=NULL;
    }
}no;

void inorder_tree(no *root,vector<int> &v)
{
    if(!root) return;
    inorder_tree(root->left,v);
    v.push_back(root->data);
    inorder_tree(root->right,v);
}
void inorder_bst(no *root,vector<int> v,int &i)
{
    if(!root) return;
    inorder_bst(root->left,v,i);
    root->data = v[i];
    i++;
    inorder_bst(root->right,v,i);
}
no *binaryTreeToBST(no *root)
{
    vector<int> v;
    inorder_tree(root,v);
    sort(v.begin(),v.end());
    int i=0;
    inorder_bst(root,v,i);
    return root;
}
void print(no *root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    no *root = new node(10);
    root->left = new node(12);
    root->right = new node(6);
    root->left->left = new node(23);
    print(root);
    cout<<endl;
    no *ans = binaryTreeToBST(root);
    print(ans);
    return 0;
}