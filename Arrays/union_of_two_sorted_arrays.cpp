/*
Given two sorted arrays arr[] and brr[] of size N and M respectively. The task is to find the union of these two arrays.
Union of two arrays can be defined as the common and distinct elements in the two arrays.

Example 1:

Input: 
N = 5, arr1[] = {1, 2, 3, 4, 5}  
M = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[],int arr2[],int n, int m)
{
    vector<int> ans;
    int i=0,j=0;
    if(arr1[i]>arr2[j])
    {
        ans.push_back(arr2[j]);
        j++;
    }
    else if(arr1[i]<arr2[j])
    {
        ans.push_back(arr1[i]);
        i++;
    }
    else
    {
        ans.push_back(arr1[i]);
        i++;
        j++;
    }
    while(i<n && j<m)
    {
        if(arr1[i]==ans.back() && i>=0)
        {
            i++;
            continue;
        }
        if(arr2[j]==ans.back() && j>=0)
        {
            j++;
            continue;
        }
        if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            ans.push_back(arr2[j]);
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while(i<n)
    {
        if(arr1[i]!=ans.back())
        {
            ans.push_back(arr1[i]);
            i++;
        }
    }
    while(j<m)
    {
        if(arr2[j]!=ans.back())
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        int arr1[N],arr2[M];

        for(int i=0;i<N;i++)
        {
            cin>> arr1[i];
        }

        for(int i=0;i<M;i++)
        {
            cin>>arr2[i];
        }
        vector<int> ans = findUnion(arr1,arr2,N,M);
        for(int i:ans)
        {
            cout<<i<<endl;
        }
        cout<<endl;
    }
}