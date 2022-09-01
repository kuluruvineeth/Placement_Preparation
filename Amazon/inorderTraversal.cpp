#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> ans;
            inorderTraversalHelper(root,ans);
            return ans;
        }
    private:
        void inorderTraversalHelper(TreeNode* root, vector<int>& ans){
            if(root!=NULL){
                inorderTraversalHelper(root->left,ans);
                ans.push_back(root->val);
                inorderTraversalHelper(root->right,ans);
            }
        }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ans = s.inorderTraversal(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}