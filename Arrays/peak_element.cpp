/*
Question : Given an array A of N integers. The task is to find a peak element in A in O( log N ) .
An array element is peak if it is not smaller than its neighbours. For corner elements, consider only one neighbour.

Example 1:

Input:
N = 3
A[] = {1,2,3}
Output: 2 
Explanation: In the given array, 
3 is the peak element as it is 
greater than its neighbour.
*/

#include<bits/stdc++.h>
using namespace std;

// peakElement Function using Binary Search method
int peakElement(int arr[], int n)
{
    int low=0, high=(n-1),mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if((mid > 0 && mid<(n-1) && arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) || (mid==0 && arr[mid]>=arr[mid+1]) || (mid==(n-1) && arr[mid]>=arr[mid-1]))
        {
            return mid;
        }
        else if(arr[mid+1]>=arr[mid])
        {
            low=(mid+1);
        }
        else if(arr[mid-1]>=arr[mid])
        {
            high=(mid-1);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int result = peakElement(a,n);
        cout<<"The peak element is : "<< a[result]<<endl;
        return 0;
    }
}