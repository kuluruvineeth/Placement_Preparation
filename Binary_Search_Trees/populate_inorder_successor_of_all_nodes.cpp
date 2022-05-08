#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left,*right,*next;
    node(int d)
    {
        data = d;
        left=right=next=NULL;
    }
}no;

void solve(no *root,no *&prev)
{
    if(!root) return;
    solve(root->left,prev);
    if(prev!=NULL)
    {
        prev->next = root;
    }
    prev=root;
    solve(root->right,prev);
}
void populateNext(no *root)
{
    no *prev=NULL;
    solve(root,prev);
}
int main()
{
    no *root = new node(10);
    root->right = new node(12);
    root->left = new node(8);
    root->left->left = new node(3);
    populateNext(root);
    no *ptr = root->left->left;
    while(ptr)
    {
        cout<<"Next of "<<ptr->data<<" is "<<(ptr->next ? ptr->next->data : -1)<<endl;
        ptr = ptr->next;
    }
    return 0;
}