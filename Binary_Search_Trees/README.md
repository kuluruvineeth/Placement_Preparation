# List of Binary Search Trees questions for Interview Preparation

## 1. [Search and Insert](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/search_and_insert.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
/*
    using iteration
    TC: O(log N) not skewed
        O(N) for skewed
*/
void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    inorderTraversal(root);
    return 0;
}
```

## 2. [Delete node in BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/delete_node_in_bst.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

no* deleteNode(no *root,int key)
{
    //base case
    if(!root) return NULL;

    //if value of root matches with the key
    if(root->data == key)
    {
        //if there is not right child then simply attach root's parent with root's child
        if(!root->right)
        {
            no *left = root->left;
            delete root;
            return left;
        }
        //if there is no left child then simply attach root's parent with root's child
        else if(!root->left)
        {
            no *right = root->right;
            delete root;
            return right;
        }
        //then swap with right-subtrees smallest child with curr-value,also BST wont change
        //alternative way we can also swap left-subtrees greatest child with curr-value,still BST wont change
        else
        {
            no *right = root->right;
            while(right->left)
            {
                right = right->left;
            }
            swap(root->data,right->data);
        }
    }
    //get deleted and arranged from the recursion
    root->left = deleteNode(root->left,key);
    root->right = deleteNode(root->right,key);
    return root;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    insert(root,217);
    inorderTraversal(root);
    no *root1 = deleteNode(root,12);
    inorderTraversal(root1);
    return 0;
}
```

## 3. [Min and Max value in BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/min_and_max_value_in_bst.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

void print(no *root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

//Function to find the minimum element in BST
int minValue(no *root)
{
    if(root==NULL) return -1;
    no *curr = root;
    while(curr->left!=NULL) curr=curr->left;
    return(curr->data);
}

//function to find maximum element in BST
int maxValue(no *root)
{
    if(root==NULL) return -1;
    no *curr = root;
    while(curr->right!=NULL) curr=curr->right;
    return curr->data;
}

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    print(root);
    cout<<"max value is : "<<maxValue(root)<<endl;
    cout<<"min value is : "<<minValue(root)<<endl;
    return 0;
}
```

## 4. [Find predecessor and successor](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/find_predecessor_and_successor.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//this function finds predecessor and successor of key in BST.
//it sets pre and suc as predecessor and successor respectively.
void findPreSuc(no *root,no*& pre,no*& suc,int key)
{
    //base case
    if(root==NULL) return;
    //if key is present at root
    if(root->data==key)
    {
        //the maximum value in left subtree is predecessor
        if(root->left!=NULL)
        {
            no *temp = root->left;
            while(temp->right!=NULL) temp = temp->right;
            pre = temp;
        }
        // the minimum value in right subtree is successor
        if(root->right!=NULL)
        {
            no *temp = root->right;
            while(temp->left!=NULL) temp=temp->left;
            suc = temp;
        }
        return;
    }
    //if key is smaller than root's key, go to left subtree
    if(root->data>key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
}

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    inorderTraversal(root);
    no *pre = NULL,*suc = NULL;
    findPreSuc(root,pre,suc,10);
    if(pre!=NULL) cout<<"Predecessor is : "<<pre->data<<endl;
    else cout<<"No predeccesor"<<endl;
    if(suc!=NULL) cout<<"Successor is : "<<suc->data<<endl;
    else cout<<"No Successor"<<endl;
    return 0;
}
```

## 5. [Check if tree is BST or not](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/check_if_tree_is_BST_or_not.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data=d;
        left = right = NULL;
    }
}no;

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

//returns true if the given tree is BST and its values are >=min and <=max
int isBSTUtil(no *root,int min,int max)
{
    if(root==NULL) return 1;

    //false if this node violates the min/max constraint
    if(root->data < min || root->data > max) return 0;

    //otherwise check the subtrees recursively tightening the min or max constraint
    return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}
//returns true if the given tree is bst
int isBST(no *root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
}

int main()
{
    no *root = new node(5);
    root->right = new node(12);
    root->right->left = new node(2);
    cout<<isBST(root)<<endl;
    return 0;
}
```

## 6. [Find lca of 2 nodes in BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/find_lca_of_2_nodes_in_BST.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

void inorderTraversal(no *root)
{
    if(root==NULL) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
/*
    iterative solution
    TC: O(H), H is the height of the tree
*/
no* lca(no *root,int n1,int n2)
{
    while(root!=NULL)
    {
        //if both n1 and n2 are smaller than root,then lca lies in left
        if(root->data > n1 && root->data > n2) root = root->left;
        //if both n1 and n2 are greater than root, then lca lies in right
        else if(root->data < n1 && root->data < n2) root= root->right;
        else break;
    }
    return root;
}
void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    inorderTraversal(root);
    no *root1 = lca(root,10,12);
    cout<<"Least common ancestor of 10 and 12 is : "<<root1->data<<endl;
    return 0;
}
```

## 7. [Find kth smallest element in BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/find_kth_smallest_in_BST.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

class Solution
{
    public:
    int ans;
    void solve(no *root,int k,int &idx)
    {
        if(!root) return;
        solve(root->left,k,idx);
        if(k==idx)
        {
            ans = root->data;
            idx++;
            return;
        }
        else idx++;
        solve(root->right,k,idx);
    }

    //return the kth smallest element in the given BST
    int kthSmallestElement(no *root,int k)
    {
        int idx = 1;
        ans = -1;
        solve(root,k,idx);
        return ans;
    }
};

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    Solution s;
    cout<<"Kth smallest element is : "<<s.kthSmallestElement(root,2)<<endl;
    return 0;
}
```

## 8. [Find Kth largest element in BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/find_kth_largest_in_BST.cpp)
```cpp
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
        left = right = NULL;
    }
}no;

class Solution
{
    public:
    int ans;
    void solve(no *root,int k,int &idx)
    {
        if(!root) return;
        solve(root->right,k,idx);
        if(k==idx)
        {
            ans = root->data;
            idx++;
            return;
        }
        else idx++;
        solve(root->left,k,idx);
    }

    //return the kth smallest element in the given BST
    int kthSmallestElement(no *root,int k)
    {
        int idx = 1;
        ans = -1;
        solve(root,k,idx);
        return ans;
    }
};

void insert(no *root,int key)
{
    no *newnode = new node(key);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    no *prev=NULL;
    no *temp=root;
    while(temp!=NULL)
    {
        if(temp->data > key)
        {
            prev=temp;
            temp=temp->left;
        }
        else if(temp->data < key)
        {
            prev=temp;
            temp=temp->right;
        }
    }
    if(prev->data > key) prev->left = newnode;
    else prev->right = newnode;
}

int main()
{
    no *root = new node(5);
    insert(root,10);
    insert(root,12);
    insert(root,2);
    Solution s;
    cout<<"Kth largest element is : "<<s.kthSmallestElement(root,2)<<endl;
    return 0;
}
```

## 9. [Convert binary tree to BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/binary_tree_to_BST.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
}no;

void inorder_tree(no *root,vector<int> &v)
{
    if(!root) return;
    inorder_tree(root->left,v);
    v.push_back(root->data);
    inorder_tree(root->right,v);
}
void inorder_bst(no *root,vector<int> v,int &i)
{
    if(!root) return;
    inorder_bst(root->left,v,i);
    root->data = v[i];
    i++;
    inorder_bst(root->right,v,i);
}
no *binaryTreeToBST(no *root)
{
    vector<int> v;
    inorder_tree(root,v);
    sort(v.begin(),v.end());
    int i=0;
    inorder_bst(root,v,i);
    return root;
}
void print(no *root)
{
    if(root==NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

int main()
{
    no *root = new node(10);
    root->left = new node(12);
    root->right = new node(6);
    root->left->left = new node(23);
    print(root);
    cout<<endl;
    no *ans = binaryTreeToBST(root);
    print(ans);
    return 0;
}
```

## 10. [Populate inorder successor of all nodes](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/populate_inorder_successor_of_all_nodes.cpp)
```cpp
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
```

## 11. [Convert BST into balanced bst](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/convert_bst_into_balanced_bst.cpp)
```cpp
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
        left = right = NULL;
    }
}no;
vector<no*> v;
void inorder(no *root,vector<no*> &v)
{
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}

no *solve(int start,int end)
{
    if(start>end) return NULL;
    int mid = (start+end)/2;
    no *root = v[mid];
    root->left = solve(start,mid-1);
    root->right = solve(mid+1,end);
    return root;
}
void print(no *root)
{
    if(!root) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

int main()
{
    no *root = new node(10);
    root->left = new node(8);
    root->left->left= new node(7);
    root->left->left->left = new node(6);
    root->left->left->left->left = new node(5);
    inorder(root,v);
    root = solve(0,v.size()-1);
    print(root);
}
```