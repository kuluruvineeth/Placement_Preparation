/*
Given an array, reverse every sub-array formed by consecutive k elements.

Examples: 

Input: 
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9] 
k = 3 
Output: 
[3, 2, 1, 6, 5, 4, 9, 8, 7]
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int k;
        cin>>k;
        for(int i=0;i<n;i+=k)
        {
            int l=i;
            int r=min(i+k-1,n-1);
            while(l<r)
            {
                swap(a[l++],a[r--]);
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}