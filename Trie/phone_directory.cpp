#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool prefix(string a, string b)
    {
        int n1=a.size();
        int n2=b.size();
        if(n1>n2)
        {
            return false;
        }
        for(int i=0;i<n1;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        set<string> st;
        for(int i=0;i<n;i++)
        {
            st.insert(contact[i]);
        }
        for(int i=0;i<s.size();i++)
        {
            string a=s.substr(0,i+1);
            vector<string> t;
            for(auto j:st)
            {
                if(prefix(a,j))
                {
                    t.push_back(j);
                }
            }
            if(t.size()==0)
            {
                t.push_back("0");
            }
            ans.push_back(t);
        }
        return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string contact[n],s;
        for(int i=0;i<n;i++)
        {
            cin>>contact[i];
        }
        cin>>s;
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n,contact,s);
        for(int i=0;i<s.size();i++)
        {
            for(auto u:ans[i])
            {
                cout<<u<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}