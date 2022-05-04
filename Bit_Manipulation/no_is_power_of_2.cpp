#include<bits/stdc++.h>
using namespace std;

// TC: O(log N)
// crux: if there is only 1 set bit then and then only it will be power of 2. try diff. combo as well but will not work.
long long countSetBit(long long n)
{
    long long count = 0;
    while(n)
    {
        if(n&1)
        {
            count++;
        }
        n >>=1;
    }
    return count;
}

bool isPowerofTwo(long long n)
{
    if(countSetBit(n) == 1LL)
    {
        return true;
    }
    return false;
}

int main()
{
    long long n;
    cin>>n;
    cout<<isPowerofTwo(n)<<endl;
    return 0;
}
