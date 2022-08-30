#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> subsets(vector<int>& nums){
            vector<vector<int>> result;
            vector<int> curr;
            dfs(nums,0,curr,result);
            return result;
        }
    private:
        void dfs(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& result){
            result.push_back(curr);
            for(int i=start;i<nums.size();i++){
                curr.push_back(nums[i]);
                dfs(nums,i+1,curr,result);
                curr.pop_back();
            }
        }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.subsets(nums);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}