#include<bits/stdc++.h>
using namespace std;

vector<int> missingandRepeating(vector<int> &A)
{
    long long int act_sum=0;
    long long int act_sum_sq=0;
    long long int exp_sum;
    long long int exp_sum_sq;
    long long int i=0;

    for(int i=0;i<A.size();i++)
    {
        act_sum = act_sum + (long long int)A[i];
        act_sum_sq = act_sum_sq + (long long int)A[i]*A[i];
    }

    exp_sum = (long long int)(A.size())*(A.size()+1)/2;
    exp_sum_sq = (long long int)(A.size())*(A.size()+1)*(2*A.size()+1)/6;

    long long int diff_sum_sq = exp_sum_sq - act_sum_sq;
    long long int diff_sum = exp_sum - act_sum;

    long long int tog = diff_sum_sq/diff_sum;

    long long int mis = (tog + diff_sum)/2;
    long long int rep = mis - diff_sum;

    vector<int> sol;
    sol.push_back((int)rep);
    sol.push_back((int)mis);

    return sol;
}

int main()
{
    vector<int> v = {3,1,2,5,3};
    vector<int>  ans = missingandRepeating(v);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}