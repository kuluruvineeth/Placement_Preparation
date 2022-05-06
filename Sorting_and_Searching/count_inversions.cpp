#include<bits/stdc++.h>
using namespace std;
/*
    Time Complexity: O(n log n),
        The algorithm used is divide and conquer, So in each level,
        one full array traversal is needed, and there are log n levels,
        so the time complexity is O(n log n).
    Space Complexity: O(n), Temporary array.
    just trace it and it will be easy to understand
*/


// This func merges two sorted arrays and returns inversion count in the arrays.
int merge(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    int inv_count = 0;
    i=left; //i is index for left subarray
    j=mid; //j is index for right subarray
    k=left; //k is index for resultant merged subarray
    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv_count += mid-i;
        }
    }
    //copy remaining elements of left subarray to temp
    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    //copy remaining elements of right subarray to temp
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    //copy back the merged elements to original array
    for(i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}

// An auxiliary recursive function that sorts the input array and returns the number of inversions in the array.
 int mergeSort(int arr[],int temp[],int left,int right)
 {
     int mid,inv_count=0;
     if(right>left)
     {
         //divide the array into two parts and call mergesort for each of the parts
         mid = (right + left)/2;

         //inversion count will be sum of inversions in left-part,right-part and number of inversions in merging
         inv_count += mergeSort(arr,temp,left,mid);
         inv_count += mergeSort(arr,temp,mid+1,right);

         //merge the two parts
         inv_count += merge(arr,temp,left,mid+1,right);
     }
     return inv_count;
 }

 int main()
 {
     int arr[] = {2,4,1,3,5};
     int n = sizeof(arr)/sizeof(arr[0]);
     int temp[n];
     cout<<"Number of inversions are : "<<mergeSort(arr,temp,0,n-1);
     return 0;
 }
