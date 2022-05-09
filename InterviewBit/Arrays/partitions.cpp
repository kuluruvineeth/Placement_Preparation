#include<bits/stdc++.h>
using namespace std;

int solve(int A,vector<int> &B)
{
    int total=0;
    for(int i=0;i<A;i++)
    {
        total+=B[i];
    }
    if(total%3!=0)
    {
        return 0;
    }
    int one_third_sum = total/3;
    int two_third_sum = 2*one_third_sum;
    int count=0;
    int sum=0;
    int one_third_count=0;
    for(int i=0;i<A-1;i++)
    {
        sum+=B[i];
        if(sum==two_third_sum)
        {
            count += one_third_count;
        }
        if(sum==one_third_sum)
        {
            one_third_count++;
        }
    }
    return count;
}

int main()
{
    vector<int> v = {1,2,3,0,3};
    cout<<"Partitions are : "<<solve(5,v)<<endl;
    return 0;
}