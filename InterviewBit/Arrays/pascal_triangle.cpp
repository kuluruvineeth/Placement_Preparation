#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            v[i].push_back(1);
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            v[i][j] = v[i-1][j] + v[i-1][j-1];
        }
    }
    return v;
}

int main()
{
    vector<vector<int>> v = pascalTriangle(5);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}