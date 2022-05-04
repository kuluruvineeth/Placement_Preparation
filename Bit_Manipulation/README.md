# List of Bit Manipulation questions for Interview Preparation

## 1. [Count set bits in num](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Bit_Manipulation/count_set_bits_in_num.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int setBits(int n)
    {
        int ans=0;
        while(n)
        {
            if(n&1)
            {
                ans++;
            }
            n = n>>1;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;
    Solution ob;
    cout<<ob.setBits(n)<<endl;
    return 0;
}
```