#include<bits/stdc++.h>
using namespace std;

#define fastread() ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n,k,sum,num,b,c[101];
vector<pair<int,int>> a;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b;
        a.push_back(make_pair(b,i));
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        sum += a[i].first;
        if(sum<=k){
            num++;
            c[i]=a[i].second;
        }else break;
    }
    cout<<num<<endl;
    for(int i=0;i<num;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}