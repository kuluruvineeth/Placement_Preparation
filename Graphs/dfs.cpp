/*
Depth First Traversal (or Search) for a graph is similar to Depth First Traversal of a tree. The only catch here is, unlike trees, graphs may contain cycles (a node may be visited twice). To avoid processing a node more than once, use a boolean visited array. 
Example: 
Input: n = 4, e = 6 
0 -> 1, 0 -> 2, 1 -> 2, 2 -> 0, 2 -> 3, 3 -> 3 
Output: DFS from vertex 1 : 1 2 0 3 
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
int visited[1005]={0};
void dfs(int x)
{
    visited[x]=1;
    cout<<x<<" ";
    for(int i=0;i<graph[x].size();i++)
    {
        int node = graph[x][i];
        if(!visited[node])
        {
            dfs(node);
        }
    }
}
int main()
{
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        //graph[y].push_back(x);
    }
    int source;
    cin>>source;
    dfs(source);
    cout<<endl;
}