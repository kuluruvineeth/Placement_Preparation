#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countBitsFlip(int a,int b)
    {
        int count=0;
        // as int can be max of 32 bit.
        for(int i=0;i<32;i++)
        {
            //checking every bit
            if((a&(1<<i)) ^ (b&(1<<i)))
            {
                count++;
            }
        }
        return count;
    }

    int countBitsFlip1(int a,int b)
    {
        //will set 1 when bit are different
        int a_xor_b = a^b;
        return __builtin_popcount(a_xor_b);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        Solution ob;
        cout<<ob.countBitsFlip1(a,b)<<endl;
        cout<<ob.countBitsFlip(a,b)<<endl;
    }
    return 0;
}