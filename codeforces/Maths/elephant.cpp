#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,pos;
    cin>>a;
    pos = a/5;
    if(a%5 > 0) pos++;
    cout<<pos;
    return 0;
}