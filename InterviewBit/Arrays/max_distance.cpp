#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &A)
{
    if(A.size()==1) return 0;
    vector<pair<int,int>> p;
    for(int i=0;i<A.size();i++)
    {
        p.push_back({A[i],i});
    }
    sort(p.begin(),p.end());
    int ans=0;
    int min_index = INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        min_index = min(min_index,p[i].second);
        ans = max(ans,p[i].second-min_index);
    }
    return ans;
}

int main()
{
    vector<int> v = {3,5,4,2};
    cout<<maxDistance(v)<<endl;
    return 0;
}