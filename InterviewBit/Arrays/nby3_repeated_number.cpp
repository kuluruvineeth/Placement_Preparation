#include<bits/stdc++.h>
using namespace std;

int appearsNBy3(vector<int> &v)
{
    int n=v.size();
    int count1=0,count2=0,first=INT_MAX,second=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(first==v[i]) count1++;
        else if(second==v[i]) count2++;
        else if(count1==0)
        {
            count1++;
            first=v[i];
        }
        else if(count2==0)
        {
            count2++;
            second=v[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==first) count1++;
        else if(v[i]==second) count2++;
    }
    if(count1>n/3) return first;
    if(count2>n/3) return second;
    return -1;
}

int main()
{
    vector<int> v= {1,2,3,1,1};
    cout<<appearsNBy3(v)<<endl;
    return 0;
}