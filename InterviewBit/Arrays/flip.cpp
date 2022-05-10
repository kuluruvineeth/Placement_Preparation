#include<bits/stdc++.h>
using namespace std;

vector<int> flip(string A)
{
    vector<int> ans;
    int n=A.size();
    bool flag=true;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        if(A[i]=='0')
        {
            arr[i]=1;
            flag=false;
        }
        else
        {
            arr[i]=-1;
        }
    }
    if(flag) return ans;
    ans.resize(2);
    int currentSum=0,maxSum=0,left=0,right=0;
    for(int i=0;i<n;i++)
    {
        currentSum += arr[i];
        if(currentSum>maxSum)
        {
            right=i;
            maxSum=currentSum;
            ans[0]=left+1;
            ans[1]=right+1;
        }
        if(currentSum<0)
        {
            left=i+1;
            currentSum=0;
        }
    }
    return ans;
}

int main()
{
    string A;
    cin>>A;
    vector<int> ans = flip(A);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}