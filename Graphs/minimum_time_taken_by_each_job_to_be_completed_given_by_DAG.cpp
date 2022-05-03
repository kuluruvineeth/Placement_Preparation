#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> g[v+1];
    vector<int> indegree(v+1,0);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        indegree[y]++;
    }
    vector<int> ans(v+1,0);
    queue<int> q;
    for(int i=1;i<=v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            ans[i]=1;
        }
    }
    while(!q.empty())
    {
        int val = q.front();
        q.pop();
        for(auto x:g[val])
        {
            indegree[x]--;
            if(indegree[x]==0)
            {
                ans[x] = ans[val] + 1;
                q.push(x);
            }
        }
    }
    for(int i=1;i<=v;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}