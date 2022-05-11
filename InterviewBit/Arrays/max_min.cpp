#include<bits/stdc++.h>
using namespace std;

int maxMin(vector<int> &A)
{
    int n=A.size();
    int maxm=A[0],minm=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]>maxm) maxm=A[i];
        else if(A[i]<minm) minm=A[i];
    }
    return maxm+minm;
}

int main()
{
    vector<int> v = {-2,1,-4,5,3};
    cout<<"Sum of min and max elements : "<<maxMin(v)<<endl;
    return 0;
}