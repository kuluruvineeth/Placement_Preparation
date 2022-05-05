#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* left,*right;
    int data,hd;
};

node* newNode(int data)
{
    node* root = new node();
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void topView(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    map<int,int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(q.size())
    {
        hd = root->hd;
        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if(m.count(hd) == 0)
        {
            m[hd] = root->data;
        }
        if(root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    cout<<"Top view of tree is : ";
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(40);
    root->left->right = newNode(60);
    root->right = newNode(30);
    root->right->left = newNode(90);
    root->right->right = newNode(100);
    topView(root);
    return 0;
}