#include<bits/stdc++.h>
using namespace std;

void print_duplicates(string s)
{
    int arr[256]; //256 as its not said there would be only alphabets
    memset(arr,0,sizeof(arr));
    for(char c:s)
    {
        arr[c - 'a']++;
    }
    for(int i=0;i<256;i++)
    {
        if(arr[i]>1)
        {
            cout<<('a' + i)<<" Count="<<arr[i]<<endl;
        }
    }
}

//using maps
void print_duplicates1(string s)
{
    map<char,int> mp;
    for(char c:s)
    {
        mp[c]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        if(i->second > 1)
        {
            cout<<i->first<<" Count="<<i->second<<endl;
        }
    }
}

int main()
{
    string s = "geeksforgeeks";
    print_duplicates(s);
    print_duplicates1(s);
}
