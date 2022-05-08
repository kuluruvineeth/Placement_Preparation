#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
//A utility function to create a new BST node
node* newNode(int d)
{
    node* temp = new node;
    temp->data = d;
    temp->right=temp->left=NULL;
    return temp;
}

/*A utility function to insert a new node with given
data in BST and find its successor*/
node* insert(node* root,int data,node*& succ)
{
    if(root==NULL) return root=newNode(data);

    //If key is smaller than root's key, go to left
    //subtree and set successor as current node
    if(data<root->data)
    {
        succ=root;
        root->left = insert(root->left,data,succ);
    }
    //go to right subtree
    else if(data>root->data)
    {
        root->right = insert(root->right,data,succ);
    }
    return root;
}

//function to replace every element with the 
//least greater element on its right
void replace(int arr[],int n)
{
    node* root = NULL;
    //start from right to left
    for(int i=n-1;i>=0;i--)
    {
        node* succ = NULL;
        //insert current element into BST and
        //find its inorder successor
        root= insert(root,arr[i],succ);

        //replace element by its inorder
        //successor in BST
        if(succ) arr[i] = succ->data;
        else //No inorder successor
            arr[i]=-1;
    }
}

int main()
{
    int arr[] = {8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};
    int n = sizeof(arr)/sizeof(arr[0]);
    replace(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}