#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums,int target)
{
    int low=0,high=nums.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]>=nums[low])
        {
            if(nums[low]<=target && nums[mid]>=target)
            {
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(nums[mid]<=target && nums[high]>=target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<search(v,target)<<endl;
    return 0;
}