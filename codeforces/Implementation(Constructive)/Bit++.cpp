#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int positive=0,negative=0;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        if(s.find('+')!=string::npos) positive++;
        else negative++;
    }
    cout<<abs(positive-negative)<<endl;
}