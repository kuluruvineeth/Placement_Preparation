#include<bits/stdc++.h>
using namespace std;

int maxsumSubArray(vector<int> &A)
{
    int n=A.size(),res,m=0;
    res=A[0];
    if(n==1) return res;
    for(int i=0;i<n;i++)
    {
        m=m+A[i];
        if(m<A[i])
        {
            m=A[i];
        }
        if(res < m) res=m;
    }
    return res;
}

int main()
{
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum subarray sum is : "<<maxsumSubArray(v)<<endl;
    return 0;
}