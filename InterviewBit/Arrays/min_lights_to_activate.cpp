#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A,int B)
{
    int count=0;
    int n=A.size(),i=0;
    while(i<n)
    {
        int left = max(i-B+1,0);
        int right = min(i+B-1,n-1);
        bool bulbFound=0;
        while(right>=left)
        {
            if(A[right--]==1)
            {
                bulbFound = 1;
                break;
            }
        }
        if(!bulbFound) return -1;
        count++;
        i = right+B;
    }
    return count;
}

int main()
{
    vector<int> A={0,0,1,1,1,0,0,1};
    cout<<solve(A,3)<<endl;
    return 0;
}