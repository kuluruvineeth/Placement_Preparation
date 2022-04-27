/*
Question - Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Example : 
Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
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
        cin>> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int flag=0,left[n],right[n];
        left[0] = a[0];
        right[n-1] = a[n-1];
        for(int i=1;i<n;i++)
        {
            left[i] = max(a[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i] = min(a[i],right[i+1]);
        }
        for(int i=1;i<=n-2;i++)
        {
            if(a[i] >= left[i] && a[i] <= right[i])
            {
                cout<<a[i]<<endl;
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
        }
    }
}