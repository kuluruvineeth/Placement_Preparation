#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);

int main()
{
    fastread();
    int t;
    int c,pos1,pos2,i;
    cin>>t;
    string s;
    while(t--)
    {
        c=0,pos1=0,pos2=0;
        cin>>s;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                pos1=i;
                break;
            }
        }
        for(i=s.length();i>=pos1;i--){
            if(s[i]=='1'){
                pos2=i;
                break;
            }
        }
        for(i=pos1;i<pos2;i++){
            if(s[i]=='0') c++;
        }
        cout<<c<<"\n";
    }
    return 0;
}