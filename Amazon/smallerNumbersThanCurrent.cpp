#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums){
            int arr[101] = {0};
            for(int i=0;i<nums.size();i++){
                arr[nums[i]]++;
            }
            int sum = 0;
            for(int i=0;i<101;i++){
                if(arr[i]!=0){
                    int v = arr[i];
                    arr[i] = sum;
                    sum += v;
                }
            }
            vector<int> ans;
            for(int i=0;i<nums.size();i++){
                int j = arr[nums[i]];
                ans.push_back(j);
            }
            return ans;
        }
};

int main(){
    Solution s;
    vector<int> nums = {8,1,2,2,3};
    vector<int> ans = s.smallerNumbersThanCurrent(nums);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}