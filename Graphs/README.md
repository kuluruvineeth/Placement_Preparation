# List of Graph Related Questions for Interview Preparation

## 1. [Breadth First Search](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/bfs.cpp)
```cpp
/*
1.Start by putting any one of the graph's vertices at the back of a queue.
2.Take the front item of the queue and add it to the visited list.
3.Create a list of that vertex's adjacent nodes. Add the ones which aren't in the visited list to the back of the queue.
4.Keep repeating steps 2 and 3 until the queue is empty.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1005];
int visited[1005]={0};
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
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int x = q.front();
        cout<<x<<" ";
        visited[x] = 1;
        q.pop();
        for(int i=0;i<graph[x].size();i++)
        {
            int node = graph[x][i];
            if(!visited[node])
            {
                q.push(node);
            }
        }
    }
    cout<<endl;
}
```

## 2. [Depth First Search](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/dfs.cpp)
```cpp
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
```