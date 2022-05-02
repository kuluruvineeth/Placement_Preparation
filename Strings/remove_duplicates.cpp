/*
Given a string S, the task is to remove all the duplicates in the given string. 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int hash[260] = {0};
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(hash[s[i]]==0)
            {
                cout<<s[i];
                hash[s[i]]++;
            }
        }
        cout<<endl;
    }

}