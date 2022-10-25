#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int count=0;
        cin>>n;
        string s;
        for(int i=1;i<=n;i++){
            cin>>s[i];
            if(s[i]=='Q') count--;
            if(s[i]=='A') count++;
            count = max(count,0);
        }
        if(count>0) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
}