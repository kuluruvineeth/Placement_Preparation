#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> plusOne(vector<int>& digits){
            for(int i=digits.size()-1;i>=0;i--){
                if(digits[i]<9){
                    digits[i]++;
                    return digits;
                }
                digits[i] = 0;
            }
            digits[0] = 1;
            digits.push_back(0);
            return digits;
        }
};

int main(){
    Solution s;
    vector<int> digits = {9,9,9};
    vector<int> ans = s.plusOne(digits);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}