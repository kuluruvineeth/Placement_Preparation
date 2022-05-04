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