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

## 12. [Merge 2 BST](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/merge_2_BST.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

/*A binary tree has data,pointer to left child
and a pointer to right child*/
class node
{
    public:
        int data;
        node* left;
        node* right;
};
//A utility function to merge two sorted arrays into one
int* merge(int arr1[],int arr2[],int m,int n);

//A helper function that stores inorder traversal of a tree in inorder array
void storeInorder(node* node,int inorder[],int* index_ptr);

//A function that constructs balanced binary search tree from sorted array
node* sortedArrayToBST(int arr[],int start,int end);

/*This function merges two balanced BSTs with roots as root1 and root2.
m and n are the sizes of the trees respectively*/
node* mergeTrees(node* root1,node* root2,int m,int n)
{
    //store inorder traversal of first tree in array arr1[]
    int* arr1 = new int[m];
    int i=0;
    storeInorder(root1,arr1,&i);

    //store inorder traversal of second tree in another array arr2[]
    int* arr2 = new int[n];
    int j=0;
    storeInorder(root2,arr2,&j);

    //merge the two sorted array into one
    int* mergedArr = merge(arr1,arr2,m,n);

    //construct a tree from the merged array and return root of the tree
    return sortedArrayToBST(mergedArr,0,m+n-1);
}

/*Helper function that allocates a new node with the given data
and NULL left and right pointers*/
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
}

//A utility function to print inorder traversal of binary tree
void printInorder(node* node)
{
    if(node==NULL) return;
    //first recur on left child
    printInorder(node->left);
    cout<<node->data<<" ";
    //now recur on right child
    printInorder(node->right);
}

//A utility function to merge two sorted arrays into one
int* merge(int arr1[],int arr2[],int m,int n)
{
    //mergeArr[] is going to contain result
    int* mergedArr = new int[m+n];
    int i=0,j=0,k=0;
    //traverse through both arrays
    while(i<m && j<n)
    {
        //pick the smaller element and put it in mergedArr
        if(arr1[i]<arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    //if there are more elements in first array
    while(i<m)
    {
        mergedArr[k] = arr1[i];
        i++;k++;
    }
    //if there are more elements in second array
    while(j<n)
    {
        mergedArr[k] = arr2[j];
        j++;k++;
    }
    return mergedArr;
}

//A helper function that stores inorder traversal of a tree rooted with node
void storeInorder(node* node,int inorder[],int* index_ptr)
{
    if(node==NULL) return;
    //first recur on left child
    storeInorder(node->left,inorder,index_ptr);
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; //increase index for next entry
    //now recur on right child
    storeInorder(node->right,inorder,index_ptr);
}

//A function that constructs balanced binary search tree from sorted array
node* sortedArrayToBST(int arr[],int start,int end)
{
    if(start>end) return NULL;
    //get the middle element and make it root
    int mid = (start+end)/2;
    node* root = newNode(arr[mid]);
    //recursively construct the left subtree and make it left child of root
    root->left = sortedArrayToBST(arr,start,mid-1);
    //recursively construct the right subtree and make it right child of root
    root->right = sortedArrayToBST(arr,mid+1,end);
    return root;
}

int main()
{
    node* root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    node* root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    node* mergedTree = mergeTrees(root1,root2,5,3);

    cout<<"Following is inorder traversal of the merged tree"<<endl;
    printInorder(mergedTree);
    return 0;
}
```

## 13. [Count pairs whose sum is x](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/count_pairs_whose_sum_is_x.cpp)
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
```

## 14. [Largest BST in binary tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/largest_bst_in_binary_tree.cpp)
```cpp
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
```

## 15. [Flatten BST to sorted list](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/flatten_BST_to_sorted_list.cpp)
```cpp
/*
    TC: O(N)
    SC: O(H), H is the height of the tree
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left=right=NULL;
    }
};

//function to print flattened binary tree
void print(node* parent)
{
    node* curr = parent;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->right;
    }
}

//function to perform inorder traversal recursively
void inorder(node* curr,node*& prev)
{
    if(curr==NULL) return;
    inorder(curr->left,prev);
    prev->left = NULL;
    prev->right = curr;
    prev=curr;
    inorder(curr->right,prev);
}

//function to flatten binary tree
node* flatten(node* parent)
{
    //dummy node
    node* dummy = new node(-1);
    //pointer to previous element
    node* prev = dummy;

    //calling the inorder traversal
    inorder(parent,prev);

    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
    //delete dummy node
    delete dummy;
    return ret;
}

int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    print(flatten(root));
    return 0;
}
```

## 16. [Count BST nodes which lies in given range](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/count_BST_nodes_which_lies_in_given_range.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    node(int d)
    {
        data=d;
        left=right=NULL;
    }
};

/*
    without ref. variable (improvisation)
    TC: O(H + K), H is height of tree and K is no. of nodes in range
*/
int getCount(node* root,int low,int high)
{
    //Base case
    if(!root) return 0;

    //Special optional case for improving efficiency
    if(root->data == high && root->data == low) return 1;

    //If current node is in range, then include it in count and
    //recur for left and right children of it
    if(root->data <=high && root->data>=low)
    {
        return 1 + getCount(root->left,low,high) + getCount(root->right,low,high);
    }
    //if current node is smaller than low, then recur for right child
    else if(root->data < low) return getCount(root->right,low,high);
    //else recur for left child
    else return getCount(root->left,low,high);
}
int main()
{
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(2);
    cout<<"Bst nodes in range 5 and 15 is : "<<getCount(root,5,15)<<endl;
    return 0;
}
```

## 17. [Replace every element with least greater ele on its right](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Search_Trees/replace_every_element_with_least_greater_ele_on_its_right.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
//A utility function to create a new BST node
node* newNode(int d)
{
    node* temp = new node;
    temp->data = d;
    temp->right=temp->left=NULL;
    return temp;
}

/*A utility function to insert a new node with given
data in BST and find its successor*/
node* insert(node* root,int data,node*& succ)
{
    if(root==NULL) return root=newNode(data);

    //If key is smaller than root's key, go to left
    //subtree and set successor as current node
    if(data<root->data)
    {
        succ=root;
        root->left = insert(root->left,data,succ);
    }
    //go to right subtree
    else if(data>root->data)
    {
        root->right = insert(root->right,data,succ);
    }
    return root;
}

//function to replace every element with the 
//least greater element on its right
void replace(int arr[],int n)
{
    node* root = NULL;
    //start from right to left
    for(int i=n-1;i>=0;i--)
    {
        node* succ = NULL;
        //insert current element into BST and
        //find its inorder successor
        root= insert(root,arr[i],succ);

        //replace element by its inorder
        //successor in BST
        if(succ) arr[i] = succ->data;
        else //No inorder successor
            arr[i]=-1;
    }
}

int main()
{
    int arr[] = {8,58,71,18,31,32,63,92,43,3,91,93,25,80,28};
    int n = sizeof(arr)/sizeof(arr[0]);
    replace(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
```