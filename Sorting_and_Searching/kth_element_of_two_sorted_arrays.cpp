#include<bits/stdc++.h>
using namespace std;

int find(int A[],int B[],int m,int n,int k_req)
{
    int k=0,i=0,j=0;
    while(i<m && j<n)
    {
        if(A[i]<B[j])
        {
            k++;
            if(k==k_req) return A[i];
            i++;
        }
        else
        {
            k++;
            if(k==k_req) return B[j];
            j++;
        }
    }
    //if array B[] is completely traversed
    while(i<m)
    {
        k++;
        if(k==k_req) return A[i];
        i++;
    }
    //if array A[] is completely traversed
    while(j<n)
    {
        k++;
        if(k==k_req) return B[j];
        j++;
    }
}

int main()
{
    int arr1[] = {2,3,6,7,9};
    int arr2[] = {1,4,8,10};
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    cout<<"Kth element of two sorted array is : "<<find(arr1,arr2,m,n,5);
    return 0;
}