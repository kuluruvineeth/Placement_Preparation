#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    int t=0,l=0,r=n-1,b=n-1;
    int d=0,count=1;
    vector<vector<int>> a(n,vector<int>(n));
    while(t<=b && l<=r)
    {
        if(d==0)
        {
            for(int i=l;i<=r;i++)
            {
                a[t][i]=count;
                count++;
            }
            d=1;
            t++;
        }
        else if(d==1)
        {
            for(int i=t;i<=b;i++)
            {
                a[i][r]=count;
                count++;
            }
            d=2;
            r--;
        }
        else if(d==2)
        {
            for(int i=r;i>=l;i--)
            {
                a[b][i]=count;
                count++;
            }
            d=3;
            b--;
        }
        else if(d==3)
        {
            for(int i=b;i>=t;i--)
            {
                a[i][l]=count;
                count++;
            }
            d=0;
            l++;
        }
    }
    return a;
}

int main()
{
    vector<vector<int>> v = generateMatrix(3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}