#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int findIndex(vector<int>& inorder,int i,int j,int val)
{
    for(auto b=i;b<=j;b++)
    {
        if(inorder[b]==val) return b;
    }
}
struct node* makeTree(vector<int>& inorder,vector<int>& postorder,int i,int j,int& p)
{
    if(i>j) return NULL;
    struct node* node = newNode(postorder[p--]);
    if(i==j) return node;
    int in = findIndex(inorder,i,j,node->data);
    node->right = makeTree(inorder,postorder,in+1,j,p);
    node->left = makeTree(inorder,postorder,i,in-1,p);
    return node;
}
struct node* buildTree(vector<int>& inorder,vector<int>& postorder)
{
    int p=postorder.size()-1;
    return inorder.empty() ? NULL : makeTree(inorder,postorder,0,inorder.size()-1,p);
}

int main()
{
    vector<int> inorder = {2,1,3};
    vector<int> postorder = {2,3,1};
    struct node* root = buildTree(inorder,postorder);
    cout<<"root : "<<root->data<<" ";
    cout<<root->left->data<<" "<<root->right->data<<endl;
    return 0;
}