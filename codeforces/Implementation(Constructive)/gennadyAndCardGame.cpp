#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k;
    int n,m;

    string s,x;
    cin>>s;

    for(int i=0;i<5;i++){
        cin>>x;
        if(x[0]==s[0] || x[1]==s[1]){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}