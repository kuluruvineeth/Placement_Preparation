#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool subsetSum(int arr[],int n,int sum)
    {
        vector<vector<bool>> tabu(n+1,vector<bool>(sum+1));
        for(int i=0;i<n+1;i++)
        {
            tabu[i][0] = true;
        }
        for(int j=1;j<sum+1;j++)
        {
            tabu[0][j] = false;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    tabu[i][j] = tabu[i-1][j-arr[i-1]] || tabu[i-1][j];
                }
                else
                {
                    tabu[i][j] = tabu[i-1][j];
                }
            }
        }
        return tabu[n][sum];
    }

    int equalPartition(int N,int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum += arr[i];
        }
        // this is crux of whole problem
        // if sum found is odd then its not possible to divide the array in 2 subset
        // and if sum found is even then we can use subset sum problem/implemetation to complete rest of the problem.
        if(sum%2)
        {
            return 0;
        }
        sum /= 2;
        return subsetSum(arr,N,sum);


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
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        Solution ob;
        cout<<ob.equalPartition(n,a)<<endl;
    }
    return 0;
}