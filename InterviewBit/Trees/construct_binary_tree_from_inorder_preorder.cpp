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
struct node* makeTree(vector<int>& preorder,vector<int>& inorder,int i,int j,int& p)
{
    if(i>j) return NULL;
    struct node* node = newNode(preorder[p++]);
    if(i==j) return node;
    int in = findIndex(inorder,i,j,node->data);
    node->left = makeTree(preorder,inorder,i,in-1,p);
    node->right = makeTree(preorder,inorder,in+1,j,p);
    return node;
}
struct node* buildTree(vector<int>& preorder,vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty()) return NULL;
    int p=0;
    return makeTree(preorder,inorder,0,inorder.size()-1,p);
}

int main()
{
    vector<int> inorder = {2,1,3};
    vector<int> preorder = {1,2,3};
    struct node* root = buildTree(preorder,inorder);
    cout<<"root : "<<root->data<<" ";
    cout<<root->left->data<<" "<<root->right->data<<endl;
    return 0;
}