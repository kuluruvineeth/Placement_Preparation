#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int a[3];
    while(t--)
    {
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        /*for(auto num:a){
            cout<<num<<" ";
        }*/
        if(a[0]+a[1]==a[2]) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}