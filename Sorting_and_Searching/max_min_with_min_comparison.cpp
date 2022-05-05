#include<bits/stdc++.h>
using namespace std;

int middle(int A,int B,int C)
{
    if(A<B)
    {
        return (B<C) ? B : max(A,C);
    }
    return (A<C) ? A : max(B,C);
}

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    cout<<middle(A,B,C)<<endl;
    return 0;
}