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

int pathSum(no* root,int sum,int &B)
{
    if(!root) return 0;
    sum += root->data;
    if(!root->left && !root->right) return sum==B;
    auto resl = pathSum(root->left,sum,B);
    auto resr = pathSum(root->right,sum,B);
    if(resl || resr) return 1;
    return 0;
}
int hasPathSum(no* A,int B)
{
    if(!A) return 0;
    return pathSum(A,0,B);
}

int main()
{
    no* root = newData(5);
    root->left = newData(4);
    root->right = newData(8);
    root->left->left = newData(11);
    root->right->left = newData(13);
    root->right->right = newData(4);
    root->right->right->right = newData(1);
    root->left->left->left = newData(7);
    root->left->left->right = newData(2);
    cout<<hasPathSum(root,22)<<endl;
    return 0;
}