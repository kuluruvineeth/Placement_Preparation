#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int m,int n)
{
    int i=0,j=0,k=m-1;
    //until i less than equal to k or j is less than m
    while(i<=k and j<n)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr2[j++],arr1[k--]);
        }
    }
    //sort first array
    sort(arr1,arr1+m);
    //sort second array
    sort(arr2,arr2+n);
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr1[m],arr2[n];
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    cout<<"After merging two sorted arrays : "<<endl;
    merge(arr1,arr2,m,n);
    for(int i=0;i<m;i++)
    {
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
}