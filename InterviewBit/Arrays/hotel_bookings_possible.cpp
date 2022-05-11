#include<bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &arrive, vector<int> &depart,int K)
{
    sort(arrive.begin(),arrive.end());
    sort(depart.begin(),depart.end());
    int i=0,j=0,c=0;
    while(i<arrive.size() && j<depart.size())
    {
        if(arrive[i]<depart[j])
        {
            c++;
            i++;
        }
        else
        {
            c--;
            j++;
        }
        if(c>K) return false;
    }
    return true;
}

int main()
{
    vector<int> a = {1,3,5};
    vector<int> d = {2,6,8};
    cout<<hotel(a,d,1)<<endl;
    return 0;
}