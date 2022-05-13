#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int n)
{
    vector<int> v;
    v.push_back(1);
    for(int i=1;i<=n;i++)
    {
        int curr = (v[i-1]*(n-i+1))/i;
        v.push_back(curr);
    }
    return v;
}

int main()
{
    vector<int>  ans = getRow(3);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}