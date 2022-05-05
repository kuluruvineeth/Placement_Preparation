#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[],int size,int n)
{
    sort(arr,arr+size);
    int i=0;
    int j=1;
    while(i<size && j<size)
    {
        if(i!=j && arr[j]-arr[i]==n)
        {
            return true;
        }
        else if(arr[j]-arr[i]<n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findPair(a,n,d)<<endl;
    return 0;
}