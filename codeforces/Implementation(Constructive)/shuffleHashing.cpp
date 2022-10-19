#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int main()
{
    int t,tag,lenP,lenH,i;
    cin>>t;
    while(t--)
    {
        string p,h;
        tag=0;
        cin>>p>>h;
        lenP = p.size();
        lenH = h.size();
        if(lenP>lenH) cout<<"NO\n";
        sort(p.begin(),p.end());
        for(int i=0;i<=(lenH-lenP);i++)
        {
            string s = h.substr(i,lenP);
            sort(s.begin(),s.end());
            if(s==p){
                tag=i;
                break;
            }
        }
        if(tag==1) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}