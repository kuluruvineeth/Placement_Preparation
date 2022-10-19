#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);
#define ll long long

int main()
{
    fastread();
    ll t,n;
    cin>>t;
    while(t--){
        priority_queue<int> pq;
        cin>>n;
        for(ll i=n;i>=1;i--){
            pq.push(i);
        }
        ll a,b,c;
        cout<<2<<endl;
        while(pq.size() > 1){
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            cout<<a<<" "<<b<<"\n";
            c = a+b;
            if(c&1) c++;
            c /=2;
            pq.push(c);
        }
    }
    return 0;
}