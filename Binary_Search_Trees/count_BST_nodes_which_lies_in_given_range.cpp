#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

/*
    without ref. variable (improvisation)
    TC: O(H + K), H is height of tree and K is no. of nodes in range
*/
int getCount(node* root,int low,int high)
{
    //Base case
    if(!root) return 0;

    //Special optional case for improving efficiency
    if(root->data == high && root->data == low) return 1;

    //If current node is in range, then include it in count and
    //recur for left and right children of it
    if(root->data <=high && root->data>=low)
    {
        return 1 + getCount(root->left,low,high) + getCount(root->right,low,high);
    }
    //if current node is smaller than low, then recur for right child
    else if(root->data < low) return getCount(root->right,low,high);
    //else recur for left child
    else return getCount(root->left,low,high);
}
int main()
{
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(2);
    cout<<"Bst nodes in range 5 and 15 is : "<<getCount(root,5,15)<<endl;
    return 0;
}