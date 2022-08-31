#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int leastInterval(vector<char>& tasks, int n){
            vector<int> count(26,0);
            int maxv = 0;
            for(auto c : tasks){
                count[c - 'A']++;
                maxv = max(maxv,count[c-'A']);
            }
            int maxc = 0;
            for(auto c : count){
                maxc += c==maxv;
            }
            return max((int)tasks.size(), (maxv-1)*(n+1)+maxc);
        }
};

int main(){
    Solution s;
    vector<char> a = {'A','A','A','B','B','B'};
    cout<<"The least amount of time required by CPU : "<<s.leastInterval(a,2)<<endl;
    return 0;
}