#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{
    int s=0,e=A.size()-1;
    vector<int> res;
    while(s<=e)
    {
        if(s==e)
        {
            res.push_back(A[s]*A[s]);
            break;
        }
        if(abs(A[s])>abs(A[e]))
        {
            res.push_back(A[s]*A[s]);
            s++;
        }
        else if(abs(A[s])<abs(A[e]))
        {
            res.push_back(A[e]*A[e]);
            e--;
        }
        else
        {
            res.push_back(A[s]*A[s]);
            s++;
            res.push_back(A[e]*A[e]);
            e--;
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    vector<int> v = {-6,-3,-1,2,4,5};
    vector<int> ans = solve(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}