#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}no;

no* newNode(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int maxDepth(no* root)
{
    if(root==NULL) return 0;
    return 1 + max(maxDepth(root->left),maxDepth(root->right));
}

int main()
{
    no* root = newNode(1);
    root->left = newNode(2);
    cout<<maxDepth(root)<<endl;
    return 0;
}