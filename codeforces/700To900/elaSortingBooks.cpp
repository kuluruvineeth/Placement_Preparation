#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

void execute(){
    int n,k;
    string str;
    cin>>n>>k>>str;
    vector<int> count_char(26,0);
    for(char c : str) count_char[c-'a']++;
    string ans="";
    for(int i=0;i<min(25,n/k);i++){
        while(k-ans.size() > count_char[i]){
            ans.push_back(i+'a');
        }
    }
    char c='a' + min(n/k, 25);
    while(k > ans.size()){
        ans += c;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        execute();
    }
    return 0;
}