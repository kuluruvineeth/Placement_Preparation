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