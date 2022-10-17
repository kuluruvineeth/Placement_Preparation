#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);

int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        string s;
        int flag=0;
        unordered_map<int,char> m;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>s;
        for(int i=0;i<n;i++){
            if(m.find(a[i])!=m.end() && m[a[i]]!=s[i]){
                cout<<"NO\n";
                flag=1;
                break;
            }
            m[a[i]] = s[i];
        }
        if(flag==0) cout<<"YES\n";
    }
    return 0;
}