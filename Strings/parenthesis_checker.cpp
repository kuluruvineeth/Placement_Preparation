/*
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.

Example: 

Input: exp = “[()]{}{[()()]()}” 
Output: Balanced
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
        stack<char> st;
        int n = s.size();
        int flag=1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else if(s[i]=='}')
            {
                if(!st.empty())
                {
                    if(st.top()=='{')
                    {
                        st.pop();
                    }
                    else
                    {
                        flag=0;
                    }
                }
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }
                    else
                    {
                        flag=0;
                    }
                }
            }
            else if(s[i]==']')
            {
                if(!st.empty())
                {
                    if(st.top()=='[')
                    {
                        st.pop();
                    }
                    else
                    {
                        flag=0;
                    }
                }
            }
        }
        if(st.empty() & flag)
        {
            cout<<"balanced"<<endl;
        }
        else
        {
            cout<<"not balanced"<<endl;
        }
    }
}