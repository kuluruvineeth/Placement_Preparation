#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int reduceTo;
        long long ans=0;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i].first = nums[i];
            v[i].second = cost[i];
        }
        sort(v.begin(),v.end());
        if(n%2) reduceTo = v[n/2].first;
        if(n%2==0){
            if(v[n/2-1].second > v[n/2].second) reduceTo = v[n/2-1].first;
            else reduceTo = v[n/2].first;
        }
        for(int i=0;i<n;i++){
            long long diff = (long long)((long long)(abs(v[i].first - reduceTo))*(long long)v[i].second);
            ans += diff;
        }
        return ans;
    }
};


int main()
{
    Solution s;
    vector<int> nums = {735103,366367,132236,133334,808160,113001,49051,735598,686615,665317,999793,426087,587000,649989,509946,743518};
    vector<int> cost = {724182,447415,723725,902336,600863,287644,13836,665183,448859,917248,397790,898215,790754,320604,468575,825614};
    long long ans = s.minCost(nums,cost);
    cout<<ans<<endl;
    return ans;
}