#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &v)
{
    int i,n=v.size(),count=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==9)
        {
            count++;
        }
        else break;
    }
    if(count==n)
    {
        vector<int> r;
        r.push_back(1);
        for(int i=0;i<n;i++)
        {
            r.push_back(0);
        }
        return r;
    }
    else if(v[n-1]==9)
    {
        int carry=1;
        for(i=n-1;i>=0 && carry==1;i--)
        {
            if(v[i]==9)
            {
                v[i]=0;
            }
            else
            {
                v[i]++;
                carry=0;
            }
        }
    }
    else v[n-1]++;
    //to remove leading zeros if any
    reverse(v.begin(),v.end());
    for(i=n-1;i>=0&&v[i]==0;i--) v.pop_back();
    reverse(v.begin(),v.end());
    return v;
}
int main()
{
    vector<int> v = {1,2,9};
    vector<int> ans = plusOne(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}