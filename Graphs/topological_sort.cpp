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