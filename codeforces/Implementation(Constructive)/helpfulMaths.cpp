#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
    string str;
    int len,i,val,siz;

    while(cin>>str)
    {
        len = str.length();
        vector<int> v;
        for(i=0;i<len;i++){
            if(str[i]=='+') continue;
            val =str[i] - '0';
            v.pb(val);
        }
        sort(v.begin(),v.end());

        siz = v.size();

        for(i=0;i<siz;i++){
            if(i==siz-1){
                cout<<v[i]<<"\n";
            }
            else{
                cout<<v[i]<<"+";
            }
        }
    }
    return 0;
}