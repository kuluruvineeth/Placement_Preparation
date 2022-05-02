/*
Given two strings, the task is to find if a string can be obtained by rotating another string two places. 
Examples: 
Input: string1 = “amazon”, string2 = “azonam” 
Output: Yes
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a,b,a1,a2;
        cin>>a;
        a1="";
        a2="";
        cin>>b;
        int l=a.size();
        a1 = a1 + a.substr(2) + a.substr(0,2);
        a2 = a2 + a.substr(l-2) + a.substr(0,l-2);
        if(a1 == b || a2 == b)
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
}