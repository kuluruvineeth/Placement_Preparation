/*
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Example: 

Input: arr[] = {3, 1, 4, 6, 5} 
Output: True 
There is a Pythagorean triplet (3, 4, 5)
*/
#include<bits/stdc++.h>
using namespace std;

bool isTriplet(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i]*arr[i];
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=2;i--)
    {
        int l=0,r=i-1;
        while(l<r)
        {
            if((arr[l]+arr[r]) == arr[i])
            {
                return true;
            }
            (arr[l] + arr[r] < arr[i])? l++:r--;
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        isTriplet(arr,n)? cout<<"Yes": cout<<"No";
        cout<<endl;
    }
    return 0;
}