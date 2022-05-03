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

## 9. [Word ladder](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/word_ladder.cpp)
```cpp
int ladderLength(string start, string end, vector<string> &wordList)
{
    queue<string> q;
    q.push(start);
    int wordSize = start.size();
    unordered_set<string> word;
    for(int i=0;i<wordList.size();i++)
    {
        word.insert(wordList[i]);
    }
    if(word.find(end)==word.end())
    {
        return 0;
    }
    int len=0;
    while(!q.empty())
    {
        len++;
        int qlen = q.size();
        for(int i=0;i<qlen;i++)
        {
            string s = q.front();
            q.pop();
            for(int j=0;j<wordSize;j++)
            {
                char org = s[j];
                for(char ch='a';ch<='z';ch++)
                {
                    s[j]=ch;
                    if(s==end)
                    {
                        return len+1;
                    }
                    if(word.find(s)==word.end())
                    {
                        continue;
                    }
                    word.erase(s);
                    q.push(s);
                }
                s[j]=org;
            }
        }
    }
    return 0;
}
```

## 10. [Minimum time taken by each job to be completed given by DAG](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/minimum_time_taken_by_each_job_to_be_completed_given_by_DAG.cpp)
```cpp
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
```

## 11. [Find whether it is possible to finish all tasks or not](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/find_whether_it_is_possible_to_finish_all_tasks_or_not.cpp)
```cpp
// A BFS based solution to check if we can finish
// all tasks or not. This solution is mainly based
// on Kahn's algorithm.
#include<bits/stdc++.h>
using namespace std;

// Returns adjacency list representation from a list of pairs.
vector<unordered_set<int>> make_graph(int numTasks,vector<pair<int,int>> &prerequisites)
{
    vector<unordered_set<int>> graph(numTasks);
    for(auto pre: prerequisites)
    {
        graph[pre.second].insert(pre.first);
    }
    return graph;
}

// Finds in-degree of every vertex
vector<int> compute_indegree(vector<unordered_set<int>> &graph)
{
    vector<int> degrees(graph.size(),0);
    for(auto neighbors:graph)
    {
        for(int neigh:neighbors)
        {
            degrees[neigh]++;
        }
    }
    return degrees;
}

// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int,int>> &prerequisites)
{
    vector<unordered_set<int>> graph = make_graph(numTasks,prerequisites);
    vector<int> degrees = compute_indegree(graph);
    for(int i=0;i<numTasks;i++)
    {
        int j=0;
        for(;j<numTasks;j++)
        {
            if(!degrees[j])
            {
                break;
            }
        }
        if(j == numTasks)
        {
            return false;
        }
        degrees[j]=-1;
        for(int neigh: graph[j])
        {
            degrees[neigh]--;
        }
    }
    return true;
}

int main()
{
    int numTasks=4;
    vector<pair<int,int>> prerequisites;
    prerequisites.push_back(make_pair(1,0));
    prerequisites.push_back(make_pair(2,1));
    prerequisites.push_back(make_pair(3,2));
    if(canFinish(numTasks,prerequisites))
    {
        cout<<"Possible to finish all tasks";
    }
    else
    {
        cout<<"Impossible to finish all tasks";
    }
    return 0;
}
```

## 12. [Number of islands](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/number_of_islands.cpp)
```cpp
void dfs(int i,int j,int vis[][501],vector<int> A[],int N, int M)
{
    if(i<0 or j<0 or i>=N or j>=M) return;
    if(A[i][j]==0)
    {
        return;
    }
    if(!vis[i][j])
    {
        vis[i][j]=1;
        dfs(i+1,j,vis,A,N,M);
        dfs(i-1,j,vis,A,N,M);
        dfs(i,j+1,vis,A,N,M);
        dfs(i,j-1,vis,A,N,M);
        dfs(i+1,j+1,vis,A,N,M);
        dfs(i-1,j-1,vis,A,N,M);
        dfs(i-1,j-1,vis,A,N,M);
        dfs(i-1,j+1,vis,A,N,M);
    }
}
int findIslands(vector<int> A[],int N,int M)
{
    int vis[501][501];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            vis[i][j]=0;
        }
    }
    int c=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(!vis[i][j] and A[i][j]==1)
            {
                dfs(i,j,vis,A,N,M);
                c++;
            }
        }
    }
    return c;
}
```

## 13. [Given sorted alien dictionary find the order of character](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Graphs/given_sorted_alien_dictionary_find_the_order_of_character.cpp)
```cpp
/*
    steps:
    1. form graph from given words by comparing (as given they are sorted)
    2. so form graph such that word from smaller to larger forms edge
    3. find topological sort
    that's it
     TC: O(N + K) + O(N + K), first for forming graph and second for dfs
    Note that there would be K vertices and at-most (N-1) edges in the graph.
*/
void dfs(int curr, string &ans, vector<int> &vis, vector<vector<int>> &g)
{
    vis[curr] = 1;
    for(auto i:g[curr])
    {
        if(!vis[i])
        {
            dfs(i,ans,vis,g);
        }
    }
    ans += (curr + 'a');
}

string findOrder(string dict[],int N,int K)
{
    vector<vector<int>> g(K);
    for(int i=0;i<N-1;i++)
    {
        string a = dict[i];
        string b = dict[i+1];
        for(int j=0;j<min(a.size(),b.size());j++)
        {
            if(a[j]!=b[j])
            {
                g[a[j]-'a'].push_back(b[j]-'a');
                break;
            }
        }
    }

    vector<int> vis(K,0);
    string ans="";

    for(int i=0;i<K;i++)
    {
        if(!vis[i])
        {
            dfs(i,ans,vis,g);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
```