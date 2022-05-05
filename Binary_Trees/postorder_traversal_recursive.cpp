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