#include<bits/stdc++.h>
using namespace std;

int countSquares(int n)
{
    int i=1;
    while((i*i)<n)
    {
        i++;
    }
    return i-1;
}

int main()
{
    int n;
    cin>>n;
    cout<<countSquares(n)<<endl;
    return 0;
}