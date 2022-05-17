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

struct node* makeBST(const vector<int>& A,int start,int end)
{
    if(start>end) return NULL;
    int mid = start + (end-start)/2;
    struct node* root = newNode(A[mid]);
    root->left = makeBST(A,start,mid-1);
    root->right = makeBST(A,mid+1,end);
    return root;
}

int main()
{
    vector<int> v = {1,2,3};
    struct node* root = makeBST(v,0,v.size()-1);
    cout<<root->data<<endl;
    return 0;
}