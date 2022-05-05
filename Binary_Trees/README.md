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

## 5. [Mirror of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/mirror_of_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}no;

// Helper function that
// allocates a new node with the
// given data and NULL left and right pointers
no* createNode(int val)
{
    no* newNode = (no*)malloc(sizeof(no));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to print the inorder traversal
void inorder(no* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

//Function to convert to mirror tree
no* mirrorTree(no* root)
{
    if(root==NULL)
    {
        return root;
    }
    no* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left)
    {
        mirrorTree(root->left);
    }
    if(root->right)
    {
        mirrorTree(root->right);
    }
    return root;
}

int main()
{
    no* tree = createNode(5);
    tree->left = createNode(3);
    tree->right = createNode(6);
    tree->left->left = createNode(2);
    tree->left->right = createNode(4);
    cout<<"Inorder traversal of original tree : ";
    inorder(tree);
    mirrorTree(tree);
    cout<<"Inorder traversal of mirror tree : ";
    inorder(tree);
    return 0;
}
```

## 6. [Inorder traversal recursive and iterative](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/inorder_traversal_iterative.cpp)
### Recursive
```cpp
//inorder traversal

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
private:
  void dfs(TreeNode *node, vector<int> &inorder)
  {
    if (node == NULL)
      return;

    dfs(node->left, inorder);
    inorder.push_back(node->val);
    dfs(node->right, inorder);
  }

public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> inorder;
    dfs(root, inorder);
    return inorder;
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
  vector<int> ans = s.inorderTraversal(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
```
### Iterative
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
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> inorder;
    stack<TreeNode *> st;
    TreeNode *node = root;
    while (true)
    {
      if (node != NULL)
      {
        st.push(node);
        node = node->left;
      }
      else
      {
        if (st.empty() == true)
          break;
        node = st.top();
        st.pop();
        inorder.push_back(node->val);
        node = node->right;
      }
    }
    return inorder;
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
  vector<int> ans = s.inorderTraversal(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
```

## 7. [Preorder traversal recursive and iterative](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/preorder_traversal_iterative.cpp)
### Recursive
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
private:
  void dfs(TreeNode *node, vector<int> &preorder)
  {
    if (node == NULL)
      return;

    preorder.push_back(node->val);
    dfs(node->left, preorder);
    dfs(node->right, preorder);
  }

public:
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> preorder;
    dfs(root, preorder);
    return preorder;
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
  vector<int> ans = s.preorderTraversal(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
```
### Iterative
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
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> preorder;
    if (root == NULL)
      return preorder;

    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
      root = st.top();
      st.pop();
      preorder.push_back(root->val);
      if (root->right != NULL)
      {
        st.push(root->right);
      }
      if (root->left != NULL)
      {
        st.push(root->left);
      }
    }
    return preorder;
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
  vector<int> ans = s.preorderTraversal(root);
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
```