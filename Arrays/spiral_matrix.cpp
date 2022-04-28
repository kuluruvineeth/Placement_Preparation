/*
Given a 2D array, print it in spiral form. See the following examples.

Examples: 

Input:  {{1,    2,   3,   4},
              {5,    6,   7,   8},
             {9,   10,  11,  12},
            {13,  14,  15,  16 }}
Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r=4,c=4;
        int a[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        int k=0,l=0;
        while(k<r && l<c)
        {
            for(int i=l;i<c;i++)
            {
                cout<<a[k][i]<<" ";
            }
            k++;
            for(int i=k;i<r;i++)
            {
                cout<<a[i][c-1]<<" ";
            }
            c--;
            if(k<r)
            {
                for(int i=c-1;i>=l;i--)
                {
                    cout<<a[r-1][i]<<" ";
                }
                r--;
            }
            if(l<c)
            {
                for(int i=r-1;i>=k;i--)
                {
                    cout<<a[i][l]<<" ";
                }
                l++;
            }
        }
    }
}