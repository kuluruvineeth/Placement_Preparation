#include<bits/stdc++.h>
using namespace std;

//DP + state machine : held -> sold -> reset -> held

class Solution{
    public:
    int maxProfit(vector<int>& prices){
        int sold = 0;
        int hold = INT_MIN;
        int rest = 0;

        for(int i=0;i<prices.size();i++){
            int prevSold = sold;
            sold = hold + prices[i];
            hold = max(hold,rest-prices[i]);
            rest = max(rest,prevSold);
        }
        return max(sold,rest);
    }
};

int main(){
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout<<"Maximum profit is : "<<s.maxProfit(prices)<<endl;
    return 0;
}