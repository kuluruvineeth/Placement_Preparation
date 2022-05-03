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