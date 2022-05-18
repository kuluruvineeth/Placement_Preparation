# List of Tree based Questions for Interview Preparation

## 1. [PathSum](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/path_sum.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}no;

no* newData(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int pathSum(no* root,int sum,int &B)
{
    if(!root) return 0;
    sum += root->data;
    if(!root->left && !root->right) return sum==B;
    auto resl = pathSum(root->left,sum,B);
    auto resr = pathSum(root->right,sum,B);
    if(resl || resr) return 1;
    return 0;
}
int hasPathSum(no* A,int B)
{
    if(!A) return 0;
    return pathSum(A,0,B);
}

int main()
{
    no* root = newData(5);
    root->left = newData(4);
    root->right = newData(8);
    root->left->left = newData(11);
    root->right->left = newData(13);
    root->right->right = newData(4);
    root->right->right->right = newData(1);
    root->left->left->left = newData(7);
    root->left->left->right = newData(2);
    cout<<hasPathSum(root,22)<<endl;
    return 0;
}
```

## 2. [Minimum depth of binary tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/min_depth_of_binary_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}no;

no* newNode(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int depth(no* root)
{
    if(root==NULL) return INT_MAX;
    if(root->left==NULL && root->right==NULL) return 1;
    return 1 + min(depth(root->left),depth(root->right)); 
}

int minDepth(no* root)
{
    if(root==NULL) return 0;
    else if(root->left==NULL && root->right==NULL) return 1;
    return depth(root);
}

int main()
{
    no* root = newNode(1);
    root->left = newNode(2);
    cout<<minDepth(root)<<endl;
    return 0;
}
```

## 3. [Maximum depth of binary tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/max_depth_of_binary_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}no;

no* newNode(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int maxDepth(no* root)
{
    if(root==NULL) return 0;
    return 1 + max(maxDepth(root->left),maxDepth(root->right));
}

int main()
{
    no* root = newNode(1);
    root->left = newNode(2);
    cout<<maxDepth(root)<<endl;
    return 0;
}
```

## 4. [Root to leaf paths with sum](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/root_to_leaf_paths_with_sum.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}no;

no* newData(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void allpaths(vector<vector<int>>& res,vector<int>& temp,no* root,int sum)
{
    if(!root) return;
    sum -= root->data;
    temp.emplace_back(root->data);
    if(!root->left && !root->right && sum==0) res.emplace_back(temp);
    if(root->left) allpaths(res,temp,root->left,sum);
    if(root->right) allpaths(res,temp,root->right,sum);
    temp.pop_back();
}
vector<vector<int>> pathSum(no* root,int sum)
{
    vector<vector<int>> sol;
    vector<int> v;
    allpaths(sol,v,root,sum);
    return sol;
}

int main()
{
    no* root = newData(5);
    root->left = newData(4);
    root->right = newData(8);
    root->left->left = newData(11);
    root->right->left = newData(13);
    root->right->right = newData(4);
    root->right->right->right = newData(1);
    root->right->right->left = newData(5);
    root->left->left->left = newData(7);
    root->left->left->right = newData(2);
    vector<vector<int>> ans = pathSum(root,22);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
```

## 5. [Sum root to leaf numbers](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/sum_root_to_leaf_numbers.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
}no;

no* newData(int data)
{
    no* root = new no;
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int sum(no* root,int val)
{
    if(root==NULL) return 0;
    val = val*10 + root->data;
    if(root->left==NULL && root->right==NULL) return val;
    return sum(root->left,val) + sum(root->right,val);
}
int sumNumbers(no* root)
{
    return sum(root,0);
}

int main()
{
    no* root = newData(6);
    root->left = newData(3);
    root->right = newData(5);
    root->left->left = newData(2);
    root->left->right = newData(5);
    root->right->right = newData(4);
    root->left->right->left = newData(7);
    root->left->right->right = newData(4);
    cout<<"Sum of all root numbers : "<<sumNumbers(root)<<endl;
    return 0;
}
```

## 6. [Path to given node](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/path_to_given_node.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

bool getPath(node* root,vector<int>& arr,int x)
{
    //if root is NULL there is no path
    if(!root) return false;
    //push the node's value in 'arr'
    arr.push_back(root->data);
    //if it is the required node return true
    if(root->data==x) return true;
    //else check whether the required node lies in the left subtree or 
    //right subtree of the current node
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;
    //required node does not lie either in the left or right
    //subtree of the current node thus,remove current node's value from
    //'arr' and then return false
    arr.pop_back();
    return false;
}

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->right = newNode(3);
    vector<int> res;
    bool re;
    re = getPath(root,res,7);
    cout<<"The path is ";
    for(auto it: res)
    {
        cout<<it<<" ";
    }
    return 0;
}
```

## 7. [Remove half nodes](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/remove_half_nodes.cpp)
```cpp
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

struct node* removeHalfNodes(struct node* root)
{
    if(!root) return NULL;
    root->left = removeHalfNodes(root->left);
    root->right = removeHalfNodes(root->right);

    if(root->left==NULL && root->right==NULL) return root;

    /*if current nodes is a half node with left child NULL,
    then it's right child is returned and replaces it in the given tree*/
    if(root->left==NULL)
    {
        struct node* new_root = root->right;
        free(root);
        return new_root;
    }
    /*if current nodes is a half node with right child NULL,
    then its left child is returned and replaces it in the given tree*/
    if(root->right==NULL)
    {
        struct node* new_root = root->left;
        free(root);
        return new_root;
    }
    return root;
}

void printInorder(struct node* root)
{
    if(root!=NULL)
    {
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}
    
int main()
{
    struct node* root =  newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);

    cout<<"Inorder traversal of given tree"<<" ";
    printInorder(root);
    struct node* newRoot = removeHalfNodes(root);

    cout<<"Inorder traversal of modified tree"<<" ";
    printInorder(newRoot);
    return 0;

}
```

## 8. [Balanced binary tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/balanced_binary_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int checkBalanced(node* root)
{
    if(root==NULL) return 1;
    else if(root->left==NULL && root->right==NULL) return 1;
    else if(root->left!=NULL && root->right!=NULL)
    {
        return min(checkBalanced(root->right),checkBalanced(root->left));
    }
    else if(root->left==NULL)
    {
        if(root->right!=NULL)
        {
            node* temp = root->right;
            if(temp->right!=NULL || temp->left!=NULL) return 0;
        }
        return 1;
    }
    else if(root->right==NULL)
    {
        if(root->left!=NULL)
        {
            node* temp = root->left;
            if(temp->right!=NULL || temp->left!=NULL) return 0;
        }
        return 1;
    }
    return 1;
}

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    //root->left->right = newNode(3);
    cout<<checkBalanced(root)<<endl;
    return 0;
}
```

## 9. [Construct binary tree from inorder and preorder](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/construct_binary_tree_from_inorder_preorder.cpp)
```cpp
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

int findIndex(vector<int>& inorder,int i,int j,int val)
{
    for(auto b=i;b<=j;b++)
    {
        if(inorder[b]==val) return b;
    }
}
struct node* makeTree(vector<int>& preorder,vector<int>& inorder,int i,int j,int& p)
{
    if(i>j) return NULL;
    struct node* node = newNode(preorder[p++]);
    if(i==j) return node;
    int in = findIndex(inorder,i,j,node->data);
    node->left = makeTree(preorder,inorder,i,in-1,p);
    node->right = makeTree(preorder,inorder,in+1,j,p);
    return node;
}
struct node* buildTree(vector<int>& preorder,vector<int>& inorder)
{
    if(preorder.empty() || inorder.empty()) return NULL;
    int p=0;
    return makeTree(preorder,inorder,0,inorder.size()-1,p);
}

int main()
{
    vector<int> inorder = {2,1,3};
    vector<int> preorder = {1,2,3};
    struct node* root = buildTree(preorder,inorder);
    cout<<"root : "<<root->data<<" ";
    cout<<root->left->data<<" "<<root->right->data<<endl;
    return 0;
}
```

## 10. [Construct binary tree from inorder and postorder](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/construct_binary_tree_from_inorder_postorder.cpp)
```cpp
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

int findIndex(vector<int>& inorder,int i,int j,int val)
{
    for(auto b=i;b<=j;b++)
    {
        if(inorder[b]==val) return b;
    }
}
struct node* makeTree(vector<int>& inorder,vector<int>& postorder,int i,int j,int& p)
{
    if(i>j) return NULL;
    struct node* node = newNode(postorder[p--]);
    if(i==j) return node;
    int in = findIndex(inorder,i,j,node->data);
    node->right = makeTree(inorder,postorder,in+1,j,p);
    node->left = makeTree(inorder,postorder,i,in-1,p);
    return node;
}
struct node* buildTree(vector<int>& inorder,vector<int>& postorder)
{
    int p=postorder.size()-1;
    return inorder.empty() ? NULL : makeTree(inorder,postorder,0,inorder.size()-1,p);
}

int main()
{
    vector<int> inorder = {2,1,3};
    vector<int> postorder = {2,3,1};
    struct node* root = buildTree(inorder,postorder);
    cout<<"root : "<<root->data<<" ";
    cout<<root->left->data<<" "<<root->right->data<<endl;
    return 0;
}
```

## 11. [Sorted array to balanced bst](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/sorted_array_to_balanced_bst.cpp)
```cpp
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

struct node* makeBST(const vector<int>& A,int start,int end)
{
    if(start>end) return NULL;
    int mid = start + (end-start)/2;
    struct node* root = newNode(A[mid]);
    root->left = makeBST(A,start,mid-1);
    root->right = makeBST(A,mid+1,end);
    return root;
}

int main()
{
    vector<int> v = {1,2,3};
    struct node* root = makeBST(v,0,v.size()-1);
    cout<<root->data<<endl;
    return 0;
}
```

## 12. [Least common ancestor](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/least_common_ancestor.cpp)
```cpp
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
```

## 13. [Merge two binary trees](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Trees/merge_two_binary_trees.cpp)
```cpp
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
void PrintInorder(struct node* root)
{
    if(root!=NULL)
    {
        PrintInorder(root->left);
        cout<<root->data<<" ";
        PrintInorder(root->right);
    }
}

struct node* mergeTrees(struct node* root1,struct node* root2)
{
    if(!root1) return root2;
    else if(!root2) return root1;
    root1->data += root2->data;
    root1->left = mergeTrees(root1->left,root2->left);
    root2->right = mergeTrees(root1->right,root2->right);
    return root1;
}

int main()
{
    struct node* root1 = newNode(1);
    root1->right = newNode(4);

    struct node* root2 = newNode(2);
    root2->right = newNode(7);

    struct node* root = mergeTrees(root1,root2);
    PrintInorder(root);
    return 0;
}
```