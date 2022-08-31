#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
            int maxCandy = *max_element(candies.begin(),candies.end());
            int n = candies.size();

            vector<bool> ans(n);

            for(int i=0;i<n;i++){
                ans[i] = (maxCandy - candies[i] <= extraCandies);
            }
            return ans;
        }
};

int main(){
    Solution s;
    vector<int> candies = {2,3,5,1,3};
    vector<bool> ans = s.kidsWithCandies(candies,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}