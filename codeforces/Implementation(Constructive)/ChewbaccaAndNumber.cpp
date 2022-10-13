#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,lastdigit,invert;
    cin>>n;
    string ans="";
    while(n){
        lastdigit = n%10;
        invert = 9 - lastdigit;
        long long int condition1 = (invert==0 && n/10==0);
        if(invert<lastdigit && !condition1){
            lastdigit = invert;
        }
        ans = to_string(lastdigit) + ans;
        n=n/10;
    }
    cout<<ans<<endl;
    return 0;
}