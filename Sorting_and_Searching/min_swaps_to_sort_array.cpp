#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]] = i;
    }
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i=0;i<nums.size();i++)
    {
        while(mp[nums[i]]!=i)
        {
            ans++;
            swap(nums[i],nums[mp[nums[i]]]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<minSwaps(v)<<endl;
    return 0;
}