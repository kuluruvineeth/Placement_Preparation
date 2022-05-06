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