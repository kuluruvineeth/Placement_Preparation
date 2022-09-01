#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int>& nums){
            int n = nums.size();
            if(n<=1) return n;
            int i = 0;

            for(int j=1;j<n;j++){
                if(nums[i]!=nums[j]){
                    i++;
                    nums[i] = nums[j];
                }
            }
            return i+1;
        }
};

int main(){
    Solution s;
    vector<int> inp = {1,1,2};
    cout<<"The answer is : "<<s.removeDuplicates(inp)<<endl;
    return 0;
}