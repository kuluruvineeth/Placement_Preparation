#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int maxLen=0,prev=INT_MIN,count=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a>prev){
            count++;
            maxLen = max(maxLen,count);
        }else if(a<=prev){
            count=1;
        } 
        prev=a;
    }
    cout<<maxLen<<"\n";
    return 0;
}