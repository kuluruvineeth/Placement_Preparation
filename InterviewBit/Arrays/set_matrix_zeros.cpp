#include<bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &A)
{
    int rows=A.size(),cols=A[0].size();
    int r=0,c=0;
    for(int i=0;i<cols;i++)
    {
        if(A[0][i]==0)
        {
            r=1;
            break;
        }
    }
    for(int i=0;i<rows;i++)
    {
        if(A[i][0]==0)
        {
            c=1;
            break;
        }
    }
    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            if(A[i][j]==0)
            {
                A[0][j]=0;
                A[i][0]=0;
            }
        }
    }
    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<cols;j++)
        {
            if(A[i][0]==0 || A[0][j]==0)
            {
                A[i][j]=0;
            }
        }
    }
    if(r==1)
    {
        for(int i=0;i<cols;i++)
        {
            A[0][i]=0;
        }
    }
    if(c==1)
    {
        for(int i=0;i<rows;i++)
        {
            A[i][0]=0;
        }
    }
}

int main()
{
    vector<vector<int>> v = {{1,0,1},{1,1,1},{1,1,1}};
    setZeros(v);
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