# List of Matrix based questions for Interview Preparation

## 1. [Spiral traversal of matrix](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Matrix/spiral_traversal_of_matrix.cpp)
```cpp
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
```

## 2. [Search element in matrix](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Matrix/search_element_in_matrix.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;
/*
    using binary search
    TC: O(log(mn))
*/
bool searchMatrix(vector<vector<int>> &matrix,int target)
{
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if(matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size(), n=matrix[0].size();
    int start = 0,end=m*n-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        int e = matrix[mid/n][mid%n];
        /* here mid/n show how many complete row do we have
         while mid%n is just that column doesn't overflow.
         */
        if(target<e)
        {
            end = mid-1;
        }
        else if(target>e)
        {
            start = mid+1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> v = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<searchMatrix(v,3)<<endl;
    return 0;
}
```

## 3. [Median in row wise sorted matrix](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Matrix/median_in_row_wise_sorted_matrix.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

//function to find median in matrix
int binaryMedian(vector<vector<int>>& matrix,int r,int c)
{
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=0;i<r;i++)
    {
        //finding the minimum element
        mn = min(mn,matrix[i][0]);

        //finding the maximum element
        mx = max(mx,matrix[i][c-1]);
    }
    int desired = (r*c+1)/2;
    while(mn<mx)
    {
        int mid = mn + (mx-mn)/2;
        int place=0;
        //find count of elements smaller than mid
        for(int i=0;i<r;i++)
        {
            place += upper_bound(matrix[i].begin(),matrix[i].begin()+c,mid) - matrix[i].begin();
        }
        if(place<desired) mn = mid+1;
        else mx = mid;
    }
    return mn;
}

int main()
{
    vector<vector<int>> v = {{1,3,5},{2,6,9},{3,6,9}};
    cout<<binaryMedian(v,3,3)<<endl;
    return 0;
}
```

## 4. [Row with maximum 1](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Matrix/row_with_maximum_1.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> arr,int m,int n)
{
    int r=0; // keeps track of row,starts at first row
    int c=n-1; // keeps track of column,starts at last column
    int max_row_index=-1; //keeps track of result row index

    //starting from top right corner
    //go left if you encounter 1
    //go down if you encounter 0
    while(r<m && c>=0)
    {
        if(arr[r][c]==1)
        {
            max_row_index = r;
            c--;
        }
        else r++;
    } 
    return max_row_index;
}

int main()
{
    vector<vector<int>> v={{0,1,1,1},{0,0,1,1},{1,1,1,1},{0,0,0,0}};
    cout<<rowWithMax1s(v,4,4)<<endl;
    return 0;
}
```