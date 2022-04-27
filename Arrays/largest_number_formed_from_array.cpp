//TIME : O(N*LOGN) , SPACE : O(1)
#include<bits/stdc++.h>
using namespace std;

int cmp(string a, string b)
{
    string ab = a+b;
    string ba = b+a;
    if(ab > ba)
    {
        return 1;
    }
    else
    {
        return 0;
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
        string s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}