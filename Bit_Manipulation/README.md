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

## 2. [Non repeating numbers](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Bit_Manipulation/non_repeating_numbers.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums)
{
    // let's assume x and y be different without pair
    int main_xor = nums[0];
    for(int i=1;i<nums.size();i++)
    {
        main_xor ^= nums[i];
    }
     // now in main_xor we have x^y as all other will be pair, by doing xor will cut each other and will be 0.

    /* here is the crux: here if we see the bits in main_xor which are set are the one different in both x and y
        thus if we again xor the array on basis of bit(choose any set bit from main_xor, least bit will be fine)
        and thus as x and y have different bits on this selected set bit and thus now both x and y will be diff.
        by ANDing as below.
     */
    /*cout<<main_xor<<endl;
    cout<<(main_xor-1)<<endl;
    cout<<(~(main_xor-1))<<endl;*/

    //to get least bit from main_xor
    int least = main_xor & (~(main_xor-1));
    /*cout<<"least : "<<least<<endl;*/

    //separating the x and y
    int x=0,y=0;
    for(auto i:nums)
    {
        if(i&least)
        {
            x ^= i;
            //cout<<"x : "<<x<<endl;
        }
        else
        {
            y ^= i;
            //cout<<"y: "<<y<<endl;
        }
    }
    if(x<y)
    {
        return {x,y};
    }
    else
    {
        return {y,x};
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(2*n+2);
        for(int i=0;i<2*n+2;i++)
        {
            cin>>v[i];
        }
        vector<int> ans = singleNumber(v);
        for(auto i:ans)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}
```

## 3. [Bits flipped](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Bit_Manipulation/bits_flipped.cpp)
```cpp
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
```

## 4. [Number is power of 2](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Bit_Manipulation/no_is_power_of_2.cpp)
```cpp
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
```

## 5. [Find pos of set bit](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Bit_Manipulation/find_pos_of_set_bit.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int findPosition(int n)
{
    int count=0,setBit=0;
    while(n)
    {
        count++;
        if(n&1)
        {
            setBit++;
        }
        n >>=1;
    }
    if(setBit>1 || setBit == 0)
    {
        return -1;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<findPosition(n)<<endl;
    return 0;
}
```