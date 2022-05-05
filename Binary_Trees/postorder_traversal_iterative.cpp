#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left, *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform postorder traversal on the tree
void postorderIterative(node* root)
{
    // create an empty stack and push the root node
    stack<node*> s;
    s.push(root);

    // create another stack to store postorder traversal
    stack<int> out;

    while(!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        node* curr = s.top();
        s.pop();
        out.push(curr->data);

        //push the left and right child of the popped node into stack
        if(curr->left)
        {
            s.push(curr->left);
        }
        if(curr->right)
        {
            s.push(curr->right);
        }
    }
    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->left->right = new node(8);

    postorderIterative(root);
    return 0;
}