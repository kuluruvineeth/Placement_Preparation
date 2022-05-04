#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int maximizeTheCuts(int n,int x,int y,int z)
    {
        vector<int> arr(n+1,-1);
        arr[0]=0;
        for(int i=1;i<=n;i++)
        {
            int mnn = INT_MIN;
            if(x<=i && arr[i-x]!=-1)
            {
                mnn = max(mnn,arr[i-x]);
            }
            if(y<=i && arr[i-y]!=-1)
            {
                mnn = max(mnn,arr[i-y]);
            }
            if(z<=i && arr[i-z]!=-1)
            {
                mnn = max(mnn,arr[i-z]);
            }
            if(mnn != INT_MIN)
            {
                arr[i] = mnn+1;
            }
        }
        return (arr[n] == -1 ? 0 : arr[n]);
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
        int x,y,z;
        cin>>x>>y>>z;
        Solution ob;
        cout<<ob.maximizeTheCuts(n,x,y,z)<<endl;
    }
    return 0;
}