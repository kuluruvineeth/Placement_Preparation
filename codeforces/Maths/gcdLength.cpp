#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

class TC{
    public:
    void solve(){
        int a,b,c;
        cin>>a>>b>>c;

        ll des_a = a-c+1;
        ll des_b = b-c+1;

        cout<<cal(2,des_a)<<string(c-1,'0')<<" "<<cal(3,des_b)<<string(c-1,'0')<<"\n";
    }

    ll cal(ll pow,ll cnt){
        ll no=pow;
        while(digit(no) < cnt){
            no *= pow;
        }
        return no;
    }

    ll digit(ll no){
        ll cnt=0;
        while(no){
            ++cnt;
            no /= 10;
        }
        return 0;
    }
};

int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--){
        TC tc;
        tc.solve();
    }
    return 0;
}