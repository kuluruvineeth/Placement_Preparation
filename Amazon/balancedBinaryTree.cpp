#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
    public:
        bool isBalanced(TreeNode* root){
            return treeDepth(root) != -1;
        }
    private:
        int treeDepth(TreeNode *node){
            if(node == NULL){
                return 0;
            }
            int left = treeDepth(node->left);
            int right = treeDepth(node->right);

            if(left==-1 || right==-1){
                return -1;
            }

            return abs(left-right) > 1 ? -1 : max(left,right) + 1;
        }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    if(s.isBalanced(root)){
        cout<<"Tree is Balanced"<<endl;
    }else{
        cout<<"Tree is not balanced"<<endl;
    }
    return 0;
}