#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            pq.push(a[i]);
        }
        int k;
        cin>>k;
        while(k--)
        {
            pq.pop();
        }
        cout<<pq.top()<<endl;
    }
}