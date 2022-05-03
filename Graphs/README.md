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

## 3. [Topological Sort](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/topological_sort.cpp)
```cpp
/*
    what is topological sorting ?
    topological sort is not for cyclic graph (as it won't be possible)
    so it is always for **directed** **acyclic** graph
    hence ""DAG""
    Topological sorting for Directed Acyclic Graph (DAG) is a linear
    ordering of vertices such that for every directed edge u v,
    vertex u comes before v in the ordering. Topological Sorting for a
    graph is not possible if the graph is not a DAG.
*/

// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using BFS (kahn's algorithm)
    here we will require inDeg vector as we won't have recursive calls
    so to check every time which vertex has how many indegree
    TC: O(V + E)
    SC: O(V) + O(V)  -> 1st for inDeg, 2nd for queue
*/
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDeg(V,0);

    //store indegrees of all
    for(int i=0;i<V;i++)
    {
        for(auto k: adj[i])
        {
            inDeg[k]++;
        }
    }
    queue<int> q;
    // get all the node with indegree=0, 
    // if there is no node with indegree=0, means it has cycle
    // if there is cycle then topological sort doesn't exist
    for(int i=0;i<V;i++)
    {
        if(inDeg[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> topoSorted;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        topoSorted.push_back(curr);
        for(auto i: adj[curr])
        {
            inDeg[i]--;
            if(inDeg[i]==0) 
            {
                q.push(i);
            }
        }
    }
    return topoSorted;
}
```

## 4. [Detecting cycle in directed graph](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/detect_cycle_in_directed_graph.cpp)
```cpp
bool isCyclic(int V, vector<int> adj[])
{
    vector<int> inDeg(V,0);

    for(int i=0;i<V;i++)
    {
        for(auto k: adj[i])
        {
            inDeg[k]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(inDeg[i]==0)
        {
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        cnt++; // instead of storing we are maintaining count record
        for(auto i: adj[curr])
        {
            inDeg[i]--;
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }
    }
     /*
        if the count of the node arranged topologically is V then for sure it
        does n't have cycle as topological sort works for only DAG
        or if it doesn't get equal to V no. of vertices means cycle
        would have been detected somewhere
    */
   if(cnt == V)
   {
       return false;
   }
   return true;
}
```

## 5. [Detect cycle in undirected graph](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/detect_cycle_in_undirected_graph.cpp)
```cpp
/*
    using DFS
    TC: O(N + E)    // N or V both are same (vertices)
    SC: O(N + E)
*/
bool checkCycle(int curr, int par, vector<int> &vis, vector<int> adj[])
{
    vis[curr] = 1;
    for(auto i: adj[curr])
    {
        if(!vis[i])
        {
            /*
                hence here dont write  "return checkCycle().." as if false we will check for other nodes
                as well
            */
           if(checkCycle(i,curr,vis,adj))
           {
               return true;
           }
        }
        // i is visited as well as it is not parent means it is cycle
        else if(i !=par)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V,0);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(checkCycle(i,-1,vis,adj))
            {
                return true;
            }
        }
    }
    return false;
}
```

## 6. [Clone Graph](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/clone_graph.cpp)
```cpp
/*
    using DFS
*/
void dfs(Node* node, Node* copy, vector<Node*> &vis)
{
    // record in vis array
    vis[copy->val] = copy;
    for(auto curr : node->neighbors)
    {
        // if not visited
        if(vis[curr->val] == null)
        {
            // make new node
            Node* newNode = new Node(curr->val);
            // save in neighbour of prev
            (copy->neighbors).push_back(newNode);
            //do dfs in both
            dfs(curr,newNode,vis);
        }
        else
        {
            // visited then push the address of visited in copy's neighbors
            (copy->neighbors).push_back(vis[curr->val]);
        }
    }
}

Node* cloneGraph(Node* node)
{
    if(!node)
    {
        return NULL;
    }
    vector<Node*> vis(1000,NULL);
    Node* newNode = new Node(node->val);
    dfs(node,newNode,vis);
    return newNode;
}
```

## 7. [Minimum steps by knight](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/minimum_steps_by_knight.cpp)
```cpp
int minStepToReachTarget(vector<int> &KinghtPos, vector<int> &TargetPos,int n)
{
    int x1 = KnightPos[0];
    int y1 = KnightPos[1];
    int x2 = TargetPos[0];
    int y2 = TargetPos[1];
    int a[1001][1001];
    if(x1==x2 and y1==y2)
    {
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(x1-1,y1-1));
    while(!q.empty())
    {
        auto cur = q.front();
        int i = cur.first;
        int j = cur.second;
        q.pop();
        if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n and a[i+1][j+2]==0)
        {
            a[i+1][j+2]=a[i][j]+1;
            q.push(make_pair(i+1,j+2));
        }
        if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and a[i-1][j+2]==0)
        {
            a[i-1][j+2]=a[i][j]+1;
            q.push(make_pair(i-1,j+2));
        }
        if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and a[i-2][j+1]==0)
        {
            a[i-2][j+1]=a[i][j]+1;
            q.push(make_pair(i-2,j+1));
        }
        if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and a[i+2][j+1]==0)
        {
            a[i+2][j+1]=a[i][j]+1;
            q.push(make_pair(i+2,j+1));
        }
        if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and a[i-1][j-2]==0)
        {
            a[i-1][j-2]=a[i][j]+1;
            q.push(make_pair(i-1,j-2));
        }
        if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and a[i+1][j-2]==0)
        {
            a[i+1][j-2]=a[i][j]+1;
            q.push(make_pair(i+1,j-2));
        }
        if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and a[i-2][j-1]==0)
        {
            a[i-2][j-1]=a[i][j]+1;
            q.push(make_pair(i-2,j-1));
        }
        if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and a[i+2][j-1]==0)
        {
            a[i+2][j-1]=a[i][j]+1;
            q.push(make_pair(i+2,j-1));
        }

    }
    return a[x2-1][y2-1];
}
```

## 8. [Making wired connections](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/making_wired_connections.cpp)
```cpp
/*
    link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
    just count the disconnected graph
*/
void dfs(int curr, vector<int> v[], vector<int> &vis)
{
    vis[curr]=1;
    for(auto i: v[curr])
    {
        if(!vis[i])
        {
            dfs(i,v,vis);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    // if cables(edges) is less than vertex-1 means all computer(vertex) won't connect
    if(connections.size() < n-1)
    {
        return -1;
    }
    vector<int> vis(n,0);
    vector<int> v[n];

    for(int i=0;i<connections.size();i++)
    {
        v[connections[i][0]].push_back(connections[i][1]);
        v[connections[i][1]].push_back(connections[i][0]);
    }
    int disconnected = 0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            disconnected++;
            dfs(i,v,vis);
        }
    }
    // dis -1 as initial network wont count 
    // the one out of which we will provide cable
    return disconnected - 1;
}
```