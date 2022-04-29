/*
Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.

Examples: 

Input : Array 1 - 2 3 6 7 9
        Array 2 - 1 4 8 10
        k = 5
Output : 6
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }
        int i=0,j=0,idx=0,ans;
        while(i<n && j<m && idx<k)
        {
            if(a[i] < b[j])
            {
                ans = a[i++];
                idx++;
            }
            else
            {
                ans = b[j++];
                idx++;
            }
        }
        while(i<n && idx<k)
        {
            ans = a[i++];
            idx++;
        }
        while(j<m && idx<k)
        {
            ans = b[j++];
            idx++;
        }
        cout<<ans<<endl;
    }
}