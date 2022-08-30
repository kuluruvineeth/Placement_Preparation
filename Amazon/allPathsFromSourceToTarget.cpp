#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph){
            vector<vector<int>> ans;
            vector<int> path;
            dfs(graph,ans,path,0);
            return ans;
        }
    private:
        void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int curr){
            path.push_back(curr);
            if(curr==graph.size()-1){
                ans.push_back(path);
            }
            else{
                for(auto x : graph[curr]){
                    dfs(graph,ans,path,x);
                }
            }
            path.pop_back();
        }
};

int main(){
    Solution s;
    vector<vector<int>> graph = {{1,2},{3},{3},{}};
    s.allPathsSourceTarget(graph);
    return 0;
}