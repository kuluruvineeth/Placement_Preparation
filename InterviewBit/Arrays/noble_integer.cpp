#include<bits/stdc++.h>
using namespace std;

int nobleInteger(vector<int> &A)
{
    int n=A.size();
    sort(A.begin(),A.end());
    for(int i=0;i<n-1;i++)
    {
        if(A[i]==A[i+1]) continue;
        if(A[i]==n-i-1) return 1;
    }
    if(A[n-1]==0) return 1;
    return -1;
}

int main()
{
    vector<int> v = {3,2,1,3};
    cout<<nobleInteger(v)<<endl;
    return 0;
}