#include<bits/stdc++.h>
using namespace std;

int minSteps(vector<int> &A,vector<int> &B)
{
    int steps = 0;
    for(int i=0;i<A.size()-1;i++)
    {
        int x = A[i];
        int y = B[i];
        int x1 = A[i+1];
        int y1 = B[i+1];
        int x_diff = abs(x-x1);
        int y_diff = abs(y-y1);
        steps += max(x_diff,y_diff);
    }
    return steps;
}

int main()
{
    vector<int> A={0,1,2};
    vector<int> B={0,1,2};
    cout<<minSteps(A,B)<<endl;
    return 0;
}