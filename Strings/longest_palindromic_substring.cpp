/*
Given a string, find the longest substring which is palindrome. 
For example, 
Input: Given string :"forgeeksskeegfor", 
Output: "geeksskeeg"
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
        int l,h;
        int maxAns = -1;
        int start=-1,end=-1;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            //Even Length
            l=i-1;
            h=i;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1 > maxAns)
                {
                    maxAns = h-l+1;
                    start = l;
                    end = h;
                }
                l--;
                h++;
            }
            //Odd Length
            l=i-1;
            h=i+1;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1 > maxAns)
                {
                    maxAns = h-l+1;
                    start = l;
                    end = h;
                }
                l--;
                h++;
            }
        }
        if(maxAns == -1)
        {
            start = 0;
            end = 0;
        }
        for(int i=start;i<=end;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}
