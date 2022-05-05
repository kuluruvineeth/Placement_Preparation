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

void bottomView(node* root)
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
        node *temp = q.front();
        q.pop();
        hd = temp->hd;
        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;
        if(temp->left)
        {
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    cout<<"Bottom view of tree is : ";
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
    //root->right->left = newNode(90);
    //root->right->right = newNode(100);
    bottomView(root);
    return 0;
}