#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int len = s.size();
    for(int i=0;i<len/2;i++)
    {
        swap(s[i],s[len-i-1]);
    }
}

int main()
{
    vector<char> v = {'h','e','l','l','o'};
    reverseString(v);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}