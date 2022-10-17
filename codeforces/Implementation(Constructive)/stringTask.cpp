#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    fastread();
    string s,t;
    cin>>s;
    ll n;
    n = s.length();
    transform(s.begin(),s.end(),s.begin(),::tolower);

    for(ll i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='y'){
            continue;
        }else{
            t += '.';
            t += s[i];
        }
    }
    cout<<t<<"\n";
    return 0;
}