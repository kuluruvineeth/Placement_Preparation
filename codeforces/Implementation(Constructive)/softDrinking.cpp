#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    int tMilk = 0, tSlice = 0,toasts=0;
    tMilk = k*l;
    tSlice = c*d;
    toasts = min(min(tMilk/nl,tSlice),p/np);
    cout<<toasts<<"\n";
    return 0;
}