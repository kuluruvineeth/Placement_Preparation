#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
}no;

class Solution
{
    public:
    int ans;
    void solve(no *root,int k,int &idx)
    {
        if(!root) return;
        solve(root->right,k,idx);
        if(k==idx)
        {
            ans = root->data;
            idx++;
            return;
        }
        else idx++;
        solve(root->left,k,idx);
    }

    //return the kth smallest element in the given BST
    int kthSmallestElement(no *root,int k)
    {
        int idx = 1;
        ans = -1;
        solve(root,k,idx);
        return ans;
    }
};

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    Solution s;
    cout<<"Kth largest element is : "<<s.kthSmallestElement(root,2)<<endl;
    return 0;
}
