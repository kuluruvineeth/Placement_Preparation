#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int n=str.size();
    int i=0;
    set<char> s;
    while(i<n){
        s.insert(str[i++]);
    }
    if(s.size()%2) cout<<"IGNORE HIM!\n";
    else cout<<"CHAT WITH HER!\n";
    return 0;
}