#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

node* newNode(int data)
{
    node* temp =  new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to print left view of
// binary tree
void printLeftView(node* root)
{
    if(!root)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        //number of nodes at current level
        int n=q.size();

        //Traverse all nodes of current level
        for(int i=1;i<=n;i++)
        {
            node* temp = q.front();
            q.pop();

            //print the left most element at the level
            if(i==1)
            {
                cout<<temp->data<<" ";
            }
            //add left node to queue
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            //add right node to queue
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    printLeftView(root);
    return 0;
}
