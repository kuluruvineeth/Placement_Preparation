#include<bits/stdc++.h>
using namespace std;
#define NUM_LINE 2
#define NUM_STATION 4

int carAssembly(int a[][NUM_STATION],int t[][NUM_STATION],int *e, int *x)
{
    int first,second,i;

    // Time taken to leave first 
    // station in line 1 
    first = e[0] + a[0][0];

    // Time taken to leave first
    // station in line 2
    second = e[1] + a[1][0];

    for(i=1;i<NUM_STATION;i++)
    {
        int up = min(first+a[0][i],second+t[1][i]+a[0][i]);
        int down = min(second+a[1][i],first+t[0][i]+a[1][i]);
        first = up;
        second = down;
    }
    // consider exit times and return minimum
    return min(first+x[0],second+x[1]);
}

int main()
{
    int a[][4] = {{4,5,3,2},{2,10,1,4}};
    int t[][4] = {{0,7,4,5},{0,9,2,8}};
    int e[] = {10,12}, x[]={18,7};
    cout<<carAssembly(a,t,e,x)<<endl;
    return 0;
}