# List of Binary Tree questions for Interview Preparation

## 1. [Level order traversal](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/level_order_traversal.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> levelorder(TreeNode *root)
  {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      int size = q.size();
      vector<int> level;
      for (int i = 0; i < size; i++)
      {
        TreeNode *node = q.front();
        q.pop();
        if (node->left != NULL)
          q.push(node->left);
        if (node->right != NULL)
          q.push(node->right);
        level.push_back(node->val);
      }
      ans.push_back(level);
    }
    return ans;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(9);

  Solution s;
  vector<vector<int>> ans = s.levelorder(root);
  for (int i = 0; i < ans.size(); i++)
  {
    for (int j = 0; j < ans[i].size(); j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
```

## 2. [Reverse Level order traversal](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/reverse_level_order_traversal.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<int> reverseLevelorder(TreeNode *root)
  {
    vector<int> ans;
    if (root == NULL)
      return ans;
    queue<TreeNode *> q;
    stack<TreeNode *> s;
    q.push(root);
    while (!q.empty())
    {
        // Print front of queue and remove it from queue
        TreeNode *node = q.front();
         /*Enqueue right child */
        if (node->right != NULL)
          q.push(node->right);
        /*Enqueue left child */
        if (node->left != NULL)
          q.push(node->left);
        s.push(node);
        q.pop();
    }
    while(s.size())
    {
        ans.push_back(s.top()->val);
        s.pop();
    }
    return ans;
  }
    
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(0);
  root->left->left = new TreeNode(7);
  root->left->right = new TreeNode(9);

  Solution s;
  vector<int> ans = s.reverseLevelorder(root);
  for(int i=0;i<ans.size();i++)
  {
      cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}
```

## 3. [Height of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/maxDepth.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;

  node(int value)
  {
    data = value;
    left = NULL;
    right = NULL;
  }
} no;

void preorder_traversal(no *node)
{
  if (node == NULL)
  {
    return;
  }
  cout << node->data << " ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

int height(no *root)
{
  if (root == NULL)
  {
    return 0;
  }

  else
  {
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if (leftheight > rightheight)
    {
      return (leftheight + 1);
    }

    else
    {
      return (rightheight + 1);
    }
  }
}

int main()
{
  no *root = new node(1);
  root->left = new node(2);
  root->left->right = new node(3);

  cout << "height of tree is : " << height(root) << endl;
  return 0;
}
```

## 4. [Diameter of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/diameter_of_tree.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;

  node(int value)
  {
    data = value;
    left = NULL;
    right = NULL;
  }
} no;

void preorder_traversal(no *node)
{
  if (node == NULL)
  {
    return;
  }
  cout << node->data << " ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

int height(no *root)
{
  if (root == NULL)
  {
    return 0;
  }

  else
  {
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if (leftheight > rightheight)
    {
      return (leftheight + 1);
    }

    else
    {
      return (rightheight + 1);
    }
  }
}

int diameter(no *root)
{
    no* temp;
    queue<no*> q;
    q.push(root);
    int mx=INT_MIN,lh,rh;
    while(q.size())
    {
        temp = q.front();

        //find height of subtrees of root
        lh = height(temp->left);
        rh = height(temp->right);

        //pushing left subtree and right subtree address
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        // storing maximum of the prev and current diameter
        mx = max(mx,lh+rh+1);
        q.pop();
    }
    return mx;
}

int main()
{
  no *root = new node(1);
  root->left = new node(2);
  root->left->right = new node(3);
  root->left->right->left = new node(4);

  cout << "Diameter of tree is : " << diameter(root) << endl;
  return 0;
}
```