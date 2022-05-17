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