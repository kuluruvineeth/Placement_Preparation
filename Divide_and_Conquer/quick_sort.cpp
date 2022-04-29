/*
QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.
The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
*/
#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int r)
{
    int pivot = a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp;
    i++;
    temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return i;
}

void quick_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int pindex = partition(a,l,r);
        quick_sort(a,l,pindex-1);
        quick_sort(a,pindex+1,r);
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
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}