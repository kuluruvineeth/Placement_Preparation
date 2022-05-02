/*
Example: Let the input string be “i.like.this.program.very.much”. The function should change the string to “much.very.program.this.like.i”
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
        stack<string> st;
        cin>>s;
        string temp;
        temp="";
        int ctr=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] != '.')
            {
                temp = temp + s[i];
            }
            else
            {
                st.push(temp);
                temp="";
                ctr++;
            }
            if(i == s.size()-1)
            {
                st.push(temp);
                temp="";
                ctr++;
            }
        }
        ctr--;
        while(!st.empty())
        {
            cout<<st.top();
            st.pop();
            if(ctr!=0)
            {
                cout<<".";
                ctr--;
            }
        }
        cout<<endl;
    }
}