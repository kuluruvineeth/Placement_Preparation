#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m,int n)
{
    if(m==1 || n==1) return 1;
    return uniquePaths(m-1,n) + uniquePaths(m,n-1);
}

int main()
{
    cout<<uniquePaths(3,3)<<endl;
    return 0;
}