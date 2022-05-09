#include<bits/stdc++.h>
using namespace std;

vector<int> candyStore(int candies[],int n,int k)
{
    sort(candies,candies+n);
    int ma=0;
    int mi=0;
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        mi += candies[i];
        i++;
        j=j-k;
    }
    reverse(candies,candies+n);
    i=0;j=n-1;
    while(i<=j)
    {
        ma += candies[i];
        i++;
        j=j-k;
    }
    return {mi,ma};
}
int main()
{
    int arr[] = {3,2,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k;cin>>k;
    vector<int> ans = candyStore(arr,n,k);
    cout<<ans[0]<<" , "<<ans[1]<<endl;
    return 0;
}