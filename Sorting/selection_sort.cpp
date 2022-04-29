/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray
*/
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mn = a[i];
        int idx=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<mn)
            {
                mn=a[j];
                idx=j;
            }
        }
        int temp;
        temp = a[i];
        a[i] = a[idx];
        a[idx] = temp;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selection_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}