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
        left=right=NULL;
    }
}no;
/*
    TC: O(N logN)
    SC: O(1)
*/
bool findPair(no* root,int key)
{
    if(!root) return false;
    if(root->data > key) return findPair(root->left,key);
    else if(root->data < key) return findPair(root->right,key);
    else return true;
}

void inorderCheck(no* root1,no *root2,int x,int& cnt)
{
    if(!root1 || root1->data>=x) return;
    if(findPair(root2,x-root1->data)) cnt++;
    inorderCheck(root1->left,root2,x,cnt);
    inorderCheck(root1->right,root2,x,cnt);
}

int countPairs(no* root1,no* root2,int x)
{
    int cnt=0;
    inorderCheck(root1,root2,x,cnt);
    return cnt;
}

int main()
{
    no *root = new node(10);
    root->left = new node(8);
    root->left->left= new node(7);

    no *root1 = new node(3);
    root1->left = new node(1);
    root1->right= new node(4);

    cout<<"Count of pairs whose sum is 11 : "<<countPairs(root,root1,11)<<endl;
    return 0;
    
}
