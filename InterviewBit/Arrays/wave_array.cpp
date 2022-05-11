#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

vector<int> wave(vector<int> &A)
{
    sort(A.begin(),A.end());
    int size = A.size();
    if(A.size()%2!=0)
    {
        size = size-1;
    }
    for(int i=0;i<size;i+=2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}

int main()
{
    vector<int> v = {1,2,3,4};
    vector<int> ans = wave(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}