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