#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a==1){
            cout<<"HARD\n";
            return 0;
        }
    }
    cout<<"EASY\n";
    return 0;
}