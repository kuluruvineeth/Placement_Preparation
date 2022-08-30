#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> sortedSquares(vector<int>& nums){
            int n = nums.size(),i=0,j=n-1,k=n-1,p1,p2;
            vector<int> ans(n);
            while(i<=j){
                p1 = nums[i]*nums[i];
                p2 = nums[j]*nums[j];
                if(p2>p1){
                    ans[k--] = p2;
                    j--;
                }else if(p2<=p1){
                    ans[k--] = p1;
                    i++;
                }
            }
            return ans;
        }
};

int main(){
    Solution s;
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> ans = s.sortedSquares(nums);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}