#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &A)
{
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(A[i]>0 && A[i]<=n)
        {
            int pos=A[i]-1;
            if(A[i]!=A[pos])
            {
                swap(A[i],A[pos]);
                i--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(A[i]!=(i+1))
        {
            return i+1;
        }
    }
    return n+1;
}

int main()
{
    vector<int> v = {3,4,-1,1};
    cout<<firstMissingPositive(v)<<endl;
    return 0;
}