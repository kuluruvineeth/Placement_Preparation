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