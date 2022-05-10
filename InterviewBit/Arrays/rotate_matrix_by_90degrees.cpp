#include<bits/stdc++.h>
using namespace std;

void rotate90Clockwise(vector<vector<int>> &v)
{
    //Transpose of matrix
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v[i].size();j++)
        {
            swap(v[i][j],v[j][i]);
        }
    }
    //Reverse individual rows
    for(int i=0;i<v.size();i++)
    {
        int low=0,high=v.size()-1;
        while(low<high)
        {
            swap(v[i][low],v[i][high]);
            low++;
            high--;
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate90Clockwise(v);
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}