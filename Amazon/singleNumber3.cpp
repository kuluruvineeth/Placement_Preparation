#include<bits/stdc++.h>
using namespace std;

/*
Find two elements that appears only once
*/
class Answer{
    public:
        vector<int> singleNumber(vector<int>& nums){
            int aXorb = 0; // the result of a xor b;
            for(auto item: nums) aXorb ^= item;
            int lastBit = (aXorb & (aXorb-1)) ^ aXorb; //the last bit that a diffs b
            int intA=0, intB = 0;
            for(auto item: nums){
                //based on the last bit, group the items into groupA(include a) and groupB
                if(item & lastBit) intA = intA ^ item;
                else intB = intB ^ item; 
            }
            return vector<int>{intA,intB};
        }
};

int main(){
    Answer s;
    vector<int> nums = {1,2,1,3,2,5};
    vector<int> ans = s.singleNumber(nums);
    cout<<"Two numbers are : "<<ans[0]<<", "<<ans[1]<<endl;
    return 0;
}