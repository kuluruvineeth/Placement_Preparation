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