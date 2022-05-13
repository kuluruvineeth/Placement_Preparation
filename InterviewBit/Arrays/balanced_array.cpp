#include<bits/stdc++.h>
using namespace std;

int Balanced(vector<int> &v)
{
    int left_odd=0;
    int left_even=0;
    int right_odd=0;
    int right_even=0;
    for(int i=0;i<v.size();i++)
    {
        if(i%2==0)
        {
            right_even += v[i];
        }
        else
        {
            right_odd += v[i];
        }
    }
    int count=0;
    for(int i=0;i<v.size();i++)
    {
        if(i%2==0)
        {
            right_even -= v[i];
            if(left_odd + right_even == left_even + right_odd)
            {
                count++;
            }
            left_even += v[i];
        }
        else
        {
            right_odd -= v[i];
            if(left_odd + right_even == left_even + right_odd)
            {
                count++;
            }
            left_odd += v[i];
        }
    }
    return count;
}

int main()
{
    vector<int> v = {5,5,2,5,8};
    cout<<Balanced(v)<<endl;
    return 0;
}