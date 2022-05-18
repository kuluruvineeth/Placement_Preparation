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
void PrintInorder(struct node* root)
{
    if(root!=NULL)
    {
        PrintInorder(root->left);
        cout<<root->data<<" ";
        PrintInorder(root->right);
    }
}

struct node* mergeTrees(struct node* root1,struct node* root2)
{
    if(!root1) return root2;
    else if(!root2) return root1;
    root1->data += root2->data;
    root1->left = mergeTrees(root1->left,root2->left);
    root2->right = mergeTrees(root1->right,root2->right);
    return root1;
}

int main()
{
    struct node* root1 = newNode(1);
    root1->right = newNode(4);

    struct node* root2 = newNode(2);
    root2->right = newNode(7);

    struct node* root = mergeTrees(root1,root2);
    PrintInorder(root);
    return 0;
}