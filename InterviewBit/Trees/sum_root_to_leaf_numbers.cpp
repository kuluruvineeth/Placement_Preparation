#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}no;

no* newData(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int sum(no* root,int val)
{
    if(root==NULL) return 0;
    val = val*10 + root->data;
    if(root->left==NULL && root->right==NULL) return val;
    return sum(root->left,val) + sum(root->right,val);
}
int sumNumbers(no* root)
{
    return sum(root,0);
}

int main()
{
    no* root = newData(6);
    root->left = newData(3);
    root->right = newData(5);
    root->left->left = newData(2);
    root->left->right = newData(5);
    root->right->right = newData(4);
    root->left->right->left = newData(7);
    root->left->right->right = newData(4);
    cout<<"Sum of all root numbers : "<<sumNumbers(root)<<endl;
    return 0;
}
