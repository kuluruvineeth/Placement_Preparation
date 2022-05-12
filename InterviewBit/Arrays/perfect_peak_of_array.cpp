#include<bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &A)
{
    int n=A.size();
    //max left element
    int mx=A[0];
    vector<int> suffix(n,INT_MAX);
    suffix[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--) suffix[i]=min(suffix[i+1],A[i+1]);
    for(int i=1;i<n-1;i++)
    {
        int current = A[i];
        if(current>mx && current<suffix[i]) return 1;
        mx=max(mx,A[i]);
    }
    return 0;
}

int main()
{
    vector<int> v = {5,1,4,3,6,8,10,7,9};
    cout<<perfectPeak(v)<<endl;
    return 0;
}