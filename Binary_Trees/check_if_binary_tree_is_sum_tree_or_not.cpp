#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left,*right;
}no;

no *newNode(int data)
{
    no *root = new no;
    root->data = data;
    root->right = root->left = NULL;
    return root;
}

int sum(no *root,bool &ans)
{
    // if root is null current data is 0;
    if(root == NULL)
    {
        return 0;
    }
    // if root is leaf node then just return the current data.
    if(root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int ls = sum(root->left,ans);
    int rs = sum(root->right,ans);

    // if its not sum tree set ans false
    if(root->data != ls+rs)
    {
        ans = false;
    }
    // return sum of children + current data itself
    return ls + root->data + rs;
}

//Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(no *root)
{
    bool ans = true;
    sum(root,ans);
    return ans;
}

int main()
{
    no *root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(2);
    cout<<isSumTree(root)<<endl;
    return 0;
}