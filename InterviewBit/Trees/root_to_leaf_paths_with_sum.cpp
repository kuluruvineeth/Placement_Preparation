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