#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(false),cin.tie(0);

int main()
{
    fastread();
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        long long a[n];
        long long oddsum=0,oddnum=0,evensum=0,evennum=0,totalsum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]%2){
                oddsum += a[i];
                oddnum++;
            } 
            else{
                evensum += a[i];
                evennum++;
            }
            totalsum += a[i];
        }
        for(int i=0;i<q;i++){
            int type,x;
            cin>>type>>x;
            long long sum=0;
            if(type==0){
                if(x%2==1){
                    oddnum += evennum;
                    sum = totalsum - evensum;
                    evensum += evennum*x;
                    totalsum = sum+evensum;
                    cout<<totalsum<<"\n";
                    evennum = 0;
                }else if(x%2==0){
                    sum = totalsum - evensum;
                    evensum += evennum*x;
                    totalsum = sum+evensum;
                    cout<<totalsum<<"\n";
                }
                
                
                /*for(int i=0;i<n;i++){
                    if(a[i]%2==0){
                        a[i] = a[i] + x;
                    }
                    sum += a[i];
                }
                cout<<sum<<"\n";*/
            }
            else if(type==1){
                if(x%2==1){
                    evennum += oddnum;
                    sum = totalsum - oddsum;
                    oddsum += oddnum*x;
                    totalsum = sum+oddsum;
                    cout<<totalsum<<"\n";
                    oddnum = 0;
                }else if(x%2){
                    sum = totalsum - oddsum;
                    oddsum += oddnum*x;
                    totalsum = sum+oddsum;
                    cout<<totalsum<<"\n";
                }
                
                /*for(int i=0;i<n;i++){
                    if(a[i]%2){
                        a[i] = a[i] + x;
                    }
                    sum += a[i];
                }
                cout<<sum<<"\n";*/
            }
        }
    }
    return 0;
}