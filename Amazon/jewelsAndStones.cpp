#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int numJewelsInStones(string jewels, string stones){
            int arr[123] = {0};
            for(char &c: jewels){
                arr[c] = 1;
            }
            int count = 0;
            for(char &c : stones){
                count += arr[c];
            }
            return count;
        }
};

int main(){
    Solution s;
    string jewels = "aA", stones = "aAAbbbb";
    cout<<"The required output is : "<<s.numJewelsInStones(jewels,stones)<<endl;
    return 0;
}