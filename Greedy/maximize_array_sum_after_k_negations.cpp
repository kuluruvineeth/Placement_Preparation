#include<bits/stdc++.h>
using namespace std;

long long int maximizeSum(long long int a[],int n,int k)
{
    sort(a,a+n);
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0 and k>0)
        {
            a[i] = -a[i];
            k--;
        }
    }
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    int x = *min_element(a,a+n);
    if(k&1) sum-=2*x;
    return sum;
}

int main()
{
    int n,k;
    cin>>n>>k;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int res= maximizeSum(a,n,k);
    cout<<"Maximum sum is : "<<res<<endl;
    return 0;
}