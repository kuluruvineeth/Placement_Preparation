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

## 8. [Postorder traversal recursive and iterative](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/preorder_traversal_iterative.cpp)
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
  void dfs(TreeNode *node, vector<int> &postorder)
  {
    if (node == NULL)
      return;

    dfs(node->left, postorder);
    dfs(node->right, postorder);
    postorder.push_back(node->val);
  }

public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> postorder;
    dfs(root, postorder);
    return postorder;
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
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left, *right;
    node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform postorder traversal on the tree
void postorderIterative(node* root)
{
    // create an empty stack and push the root node
    stack<node*> s;
    s.push(root);

    // create another stack to store postorder traversal
    stack<int> out;

    while(!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        node* curr = s.top();
        s.pop();
        out.push(curr->data);

        //push the left and right child of the popped node into stack
        if(curr->left)
        {
            s.push(curr->left);
        }
        if(curr->right)
        {
            s.push(curr->right);
        }
    }
    while(!out.empty())
    {
        cout<<out.top()<<" ";
        out.pop();
    }
}

int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->left = new node(5);
    root->right->right = new node(6);
    root->right->left->left = new node(7);
    root->right->left->right = new node(8);

    postorderIterative(root);
    return 0;
}
```

## 9. [Leftview of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/leftview_of_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

node* newNode(int data)
{
    node* temp =  new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to print left view of
// binary tree
void printLeftView(node* root)
{
    if(!root)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        //number of nodes at current level
        int n=q.size();

        //Traverse all nodes of current level
        for(int i=1;i<=n;i++)
        {
            node* temp = q.front();
            q.pop();

            //print the left most element at the level
            if(i==1)
            {
                cout<<temp->data<<" ";
            }
            //add left node to queue
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            //add right node to queue
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    printLeftView(root);
    return 0;
}
```

## 10. [Right view of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/rightview_of_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

node* newNode(int data)
{
    node* temp =  new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to print right view of
// binary tree
void printrightView(node* root)
{
    if(!root)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        //number of nodes at current level
        int n=q.size();

        //Traverse all nodes of current level
        for(int i=1;i<=n;i++)
        {
            node* temp = q.front();
            q.pop();

            //print the right most element at the level
            if(i==n)
            {
                cout<<temp->data<<" ";
            }
            //add left node to queue
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            //add right node to queue
            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(8);
    root->right->right = newNode(15);
    root->right->left = newNode(12);
    root->right->right->left = newNode(14);
    printrightView(root);
    return 0;
}
```

## 11. [Top view of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/topview_of_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* left,*right;
    int data,hd;
};

node* newNode(int data)
{
    node* root = new node();
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void topView(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    map<int,int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(q.size())
    {
        hd = root->hd;
        // count function returns 1 if the container
        // contains an element whose key is equivalent
        // to hd, or returns zero otherwise.
        if(m.count(hd) == 0)
        {
            m[hd] = root->data;
        }
        if(root->left)
        {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if(root->right)
        {
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    cout<<"Top view of tree is : ";
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(40);
    root->left->right = newNode(60);
    root->right = newNode(30);
    root->right->left = newNode(90);
    root->right->right = newNode(100);
    topView(root);
    return 0;
}
```

## 12. [Bottom view of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/bottomview_of_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    node* left,*right;
    int data,hd;
};

node* newNode(int data)
{
    node* root = new node();
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void bottomView(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    map<int,int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
    while(q.size())
    {
        node *temp = q.front();
        q.pop();
        hd = temp->hd;
        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;
        if(temp->left)
        {
            temp->left->hd = hd - 1;
            q.push(temp->left);
        }
        if(temp->right)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
    }
    cout<<"Bottom view of tree is : ";
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->second<<" ";
    }
}

int main()
{
    node* root = newNode(10);
    root->left = newNode(20);
    root->left->left = newNode(40);
    root->left->right = newNode(60);
    root->right = newNode(30);
    //root->right->left = newNode(90);
    //root->right->right = newNode(100);
    bottomView(root);
    return 0;
}
```

## 13. [Zigzag traversal of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/zigzag_traversal_of_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

vector<int> zigzagTraversal(node* root)
{
    if(root==NULL)
    {
        return {};
    }
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    bool flag = false;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            node* node = q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        flag = !flag;
        if(flag==false)
        {
            reverse(level.begin(),level.end());
        }
        for(int i=0;i<level.size();i++)
        {
            ans.push_back(level[i]);
        }
        
    }
    return ans;
}

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main()
{
    vector<int> v;
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    cout<<"Zigzag order traversal of binary tree is : ";
    v = zigzagTraversal(root);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
```

## 14. [Check Balanced of tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/check_balanced.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;

  node(int x) : data(x), left(NULL), right(NULL)
  {
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

int checkheight(no *node)
{
  if (node == NULL)
  {
    return 0;
  }

  int leftheight = checkheight(node->left);
  if (leftheight == -1)
  {
    return -1;
  }

  int rightheight = checkheight(node->right);
  if (rightheight == -1)
  {
    return -1;
  }

  if (abs(leftheight - rightheight) > 1)
  {
    return -1;
  }

  else
  {
    return 1 + max(leftheight, rightheight);
  }
}

bool checkbalance(no *root)
{
  if (checkheight(root) == -1)
  {
    return false;
  }
  return true;
}

int main()
{
  no *root = new node(4);
  root->right = new node(5);
  root->left = new node(6);
  //root->right->right = new node(6);
  cout << checkbalance(root) << endl;
  preorder_traversal(root);
}
```

## 15. [Binary tree into sum tree](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/binary_tree_into_sum_tree.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node *left;
    node *right;
};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
int toSumTree(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    // store the old value
    int old_val = root->data;
    root->data = toSumTree(root->left) + toSumTree(root->right);

    // Return the sum of values of nodes
    // in left and right subtrees and
    // old_value of this node
    return root->data + old_val;

}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}

node* newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    node *root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    toSumTree(root);
    cout<<"Inorder traversal of sum tree : ";
    inorder(root);
    return 0;
}
```

## 16. [Check if binary tree is sum tree or not](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Binary_Trees/check_if_binary_tree_is_sum_tree_or_not.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *left,*right;
}no;

no *newNode(int data)
{
    no *root = new no;
    root->data = data;
    root->right = root->left = NULL;
    return root;
}

int sum(no *root,bool &ans)
{
    // if root is null current data is 0;
    if(root == NULL)
    {
        return 0;
    }
    // if root is leaf node then just return the current data.
    if(root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    int ls = sum(root->left,ans);
    int rs = sum(root->right,ans);

    // if its not sum tree set ans false
    if(root->data != ls+rs)
    {
        ans = false;
    }
    // return sum of children + current data itself
    return ls + root->data + rs;
}

//Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(no *root)
{
    bool ans = true;
    sum(root,ans);
    return ans;
}

int main()
{
    no *root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(2);
    cout<<isSumTree(root)<<endl;
    return 0;
}
```