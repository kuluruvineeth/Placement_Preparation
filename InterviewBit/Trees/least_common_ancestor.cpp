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

bool find(struct node* root,int val)
{
    if(!root) return false;
    if(root->data==val) return true;
    if((root->left && find(root->left,val)) || (root->right && find(root->right,val)))
    {
        return true;
    }
    return false;
}
struct node* LCA(struct node* root,int val1,int val2)
{
    if(!root || root->data==val1 || root->data==val2) return root;
    auto L = LCA(root->left,val1,val2);
    auto R = LCA(root->right,val1,val2);
    if(L && R)
    {
        return root;
    } 
    return L ? L : R;
}
int lca(struct node* root,int val1,int val2)
{
    if(!find(root,val1) || !find(root,val2))
    {
        return -1;
    }
    auto ancestor = LCA(root,val1,val2);
    if(ancestor) return ancestor->data;
    return -1;
}

int main()
{
    struct node* root = newNode(3);
    root->right = newNode(1);
    root->left = newNode(5);
    root->right->right = newNode(8);
    cout<<"Least common ancestor of 5 and 1 is : "<<lca(root,5,1)<<endl;
    return 0;
}