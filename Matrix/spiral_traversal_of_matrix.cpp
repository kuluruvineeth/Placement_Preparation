#include<bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
/*
    recursive approach
    Time Complexity: O(m*n). To traverse the matrix O(m*n) time is required.
    Space Complexity: O(1). No extra space is required.
*/
// i=starting row index,j=starting column index,m=ending row index,n=ending column index
void print(int arr[R][C],int i,int j,int m,int n)
{
    //if i or j lies outside matrix
    if(i>=m or j>=n) return;
    //print first row
    for(int p=j;p<n;p++) cout<<arr[i][p]<<" ";
    //print last column
    for(int p=i+1;p<m;p++) cout<<arr[p][n-1]<<" ";
    
    //print last row, if last and first row are not same
    if((m-1)!=i)
    {
        for(int p=n-2;p>=j;p--) cout<<arr[m-1][p]<<" ";
    }
    //print first column if last and first column are not same
    if((n-1)!=j)
    {
        for(int p=m-2;p>i;p--) cout<<arr[p][j]<<" ";
    }
    print(arr,i+1,j+1,m-1,n-1);
}

int main()
{
    int a[R][C] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    print(a,0,0,R,C);
    return 0;
}