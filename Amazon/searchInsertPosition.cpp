#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int searchInsert(vector<int>& nums, int target){
            int low=0,high=nums.size()-1,pos;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target){
                    high = mid-1;
                    pos = mid;
                }else{
                    low=mid+1;
                    pos=mid+1;
                }
            }
            return pos;
        }
};

int main(){
    Solution s;
    vector<int> nums = {1,3,5,6};
    cout<<"The position is : "<<s.searchInsert(nums,2)<<endl;
    return 0;
}