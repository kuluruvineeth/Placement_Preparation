#include<bits/stdc++.h>
using namespace std;

vector<int> findPerm(string A,int B)
{
    int small=1;
    int large=B;
    vector<int> ans;
    for(int i=0;i<=A.size();i++)
    {
        if(A[i]=='I')
        {
            ans.push_back(small);
            small++;
        }
        else
        {
            ans.push_back(large);
            large--;
        }
    }
    return ans;
}

int main()
{
    vector<int> res = findPerm("ID",3);
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}