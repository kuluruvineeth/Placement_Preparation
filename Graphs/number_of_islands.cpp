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