#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int solve()
{
    string s;
    cin>>s;
    char c = s[s.size()-1];
    if(c=='M') return 0;
    int t = s.size();
    return c=='S'?-t:+t;
}

int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--){
        int s=solve();
        int t=solve();
        cout<<(s<t?"<\n":s>t?">\n":"=\n");
    }
    return 0;
}