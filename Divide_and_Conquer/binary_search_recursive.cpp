#include<bits/stdc++.h>
using namespace std;

int binary_search_recursive(int a[],int l,int r,int x)
{
    if(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        else if(a[mid]>x)
        {
            return binary_search_recursive(a,l,mid-1,x);
        }
        else
        {
            return binary_search_recursive(a,mid+1,r,x);
        }
    }
    return -1;
}

int main()
{
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    int idx = binary_search_recursive(a,0,n-1,x);
    if(idx==-1)
    {
        cout<<"Element not found!"<<endl;
    }
    else
    {
        cout<<"Element found at index "<<idx+1<<endl;
    }
}