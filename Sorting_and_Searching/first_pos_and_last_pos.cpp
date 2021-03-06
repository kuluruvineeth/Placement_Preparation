#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[],int n,int x)
{
    int low=0,high=n-1,first_occ=-1,last_occ=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>x)
        {
            high = mid - 1;
        }
        else if(arr[mid]<x)
        {
            low = mid + 1;
        }
        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else
        {
            first_occ = mid;
            high = mid - 1;
        }
    }

    low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>x)
        {
            high = mid - 1;
        }
        else if(arr[mid]<x)
        {
            low = mid + 1;
        }
        // If arr[mid] is same as x, we
        // update res and move to the right
        // half
        else
        {
            last_occ = mid;
            low = mid + 1;
        }
    }
    return {first_occ,last_occ};
}

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> v = find(a,n,x);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}