/*
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
*/

#include<bits/stdc++.h>
using namespace std;

int equilibrium_point(int a[],int n)
{
    int sum=0,leftsum=0,rightsum;

    for(int i=0;i<n;i++)
    {
        sum += a[i];
    }
    rightsum = sum;
    for(int i=0;i<n;i++)
    {
        rightsum -= a[i];
        if(leftsum == rightsum)
        {
            return i+1;
        }
        leftsum += a[i];
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<equilibrium_point(a,n)<<endl;
}