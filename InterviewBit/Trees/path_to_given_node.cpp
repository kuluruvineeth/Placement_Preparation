#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

bool getPath(node* root,vector<int>& arr,int x)
{
    //if root is NULL there is no path
    if(!root) return false;
    //push the node's value in 'arr'
    arr.push_back(root->data);
    //if it is the required node return true
    if(root->data==x) return true;
    //else check whether the required node lies in the left subtree or 
    //right subtree of the current node
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;
    //required node does not lie either in the left or right
    //subtree of the current node thus,remove current node's value from
    //'arr' and then return false
    arr.pop_back();
    return false;
}

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->right = newNode(3);
    vector<int> res;
    bool re;
    re = getPath(root,res,7);
    cout<<"The path is ";
    for(auto it: res)
    {
        cout<<it<<" ";
    }
    return 0;
}