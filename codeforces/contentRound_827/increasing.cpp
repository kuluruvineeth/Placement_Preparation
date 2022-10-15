#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int flag=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            if(a[i+1]<=a[i]){
                cout<<"NO"<<"\n";
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"YES"<<"\n";
    }
    return 0;
}