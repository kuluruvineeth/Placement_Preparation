#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n=A.size();
    //finding best on right side
    vector<int> suffix(n);
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1) suffix[i]=A[i];
        else suffix[i] = max(suffix[i+1],A[i]);
    }
    //finding best on left side
    set<int> s;
    s.insert(A[0]);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        s.insert(A[i]);
        auto it = s.find(A[i]);
        if(it!=s.begin() && suffix[i]!=A[i])
            ans = max(ans,(*--it)+A[i]+suffix[i]);
        
    }
    return ans;
}

int main()
{
    vector<int> v = {2,5,3,1,4,9};
    cout<<"Max triplet sum is : "<<solve(v)<<endl;
    return 0;
}
