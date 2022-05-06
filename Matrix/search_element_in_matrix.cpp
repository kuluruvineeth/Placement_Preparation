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
