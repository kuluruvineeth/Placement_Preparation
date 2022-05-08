#include<bits/stdc++.h>
using namespace std;

/*A binary tree node has data,pointer to left child and 
pointer to right child*/
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/*Helper function that allocates a new node with the given data
and NULL left and right pointers.*/
struct node* newNode(int data)
{
    struct node* Node = new node;
    Node->data = data;
    Node->left = Node->right = NULL;
    return Node;
}

//Information to be returned by every node in bottom up traversal
struct Info
{
    int sz; //size of subtree
    int max; //min value in subtree
    int min; //max value in subtree
    int ans; //size of largest BST which is subtree of current node
    bool isBST; //If subtree is BST
};

//Returns Information about subtree. The Information also includes size of
// largest subtree which is a BST.
Info largestBSTBT(node* root)
{
    //Base cases : when tree is empty or it has
    //one child
    if(root==NULL) return {0,INT_MIN,INT_MAX,0,true};
    if(root->left==NULL && root->right==NULL) return {1,root->data,root->data,1,true};

    //Recur for left subtree and right subtrees
    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    //create a return variable and initialize its size
    Info ret;
    ret.sz = (1+l.sz+r.sz);

    //If whole tree rooted under current root is BST
    if(l.isBST && r.isBST && l.max < root->data && r.min > root->data)
    {
        ret.min = min(l.min,min(r.min,root->data));
        ret.max = max(r.max,max(l.max,root->data));
        //update answer for tree rooted under
        ret.ans = ret.sz;
        ret.isBST = true;
        return ret;
    }

    //If whole tree is not BST, return maximum of left and right subtrees
    ret.ans = max(l.ans,r.ans);
    ret.isBST = false;
    return ret;
}
int main()
{
    struct node* root = newNode(60);
    root->left = newNode(65);
    root->right = newNode(70);
    root->left->left = newNode(50);
    cout<<"Size of the largest BST is : "<<largestBSTBT(root).ans<<endl;
    return 0;
}

