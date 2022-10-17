#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        if(grid.size()==0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        unordered_map<string,int> lookup;
        return countPaths(grid,m-1,n-1,k,sum,lookup);
    }
    
    int countPaths(vector<vector<int>> &grid,int m,int n,int k,int sum,unordered_map<string,int> &lookup){
        
        if(m==0 && n==0){
            if(sum%k==0) return 1;
            else return 0;
        }
        
        string key = to_string(m) + "|" + to_string(n) + "|" + to_string(sum%k);
        
        if(lookup.find(key)==lookup.end()){
            if(m==0){
                lookup[key] = countPaths(grid,0,n-1,k,(sum+grid[m][n])%MOD,lookup);
            }
            else if(n==0){
                lookup[key] = countPaths(grid,m-1,0,k,(sum+grid[m][n])%MOD,lookup);
            }
            else{
                 lookup[key] = countPaths(grid,m-1,n,k,(sum+grid[m][n])%MOD,lookup) + countPaths(grid,m,n-1,k,(sum+grid[m][n])%MOD,lookup);
            }
        }
       return lookup[key];
    }
};

int main(){
    Solution s;
    int n = 3;
    vector<vector<int>> v{{5,2,4},{3,0,5},{0,7,2}};
    int ans = s.numberOfPaths(v,n);
    return ans;
}