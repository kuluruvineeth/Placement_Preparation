#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int n,vector<vector<int>> mat)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp.push_back(mat[i][j]);
        }
    }
    sort(temp.begin(),temp.end());
    int k=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j] = temp[k++];
        }
    }
    return mat;
}

int main()
{
    vector<vector<int>> v = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    vector<vector<int>> ans = sortedMatrix(4,v);
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}