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