#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &A)
{
   int slow=A[0];
   int fast=A[A[0]];
   while(slow!=fast)
   {
       slow=A[slow];
       fast=A[A[fast]];
   }
   slow=0;
   while(slow!=fast)
   {
       slow=A[slow];
       fast=A[fast];
   }
   return slow;
}

int main()
{
    vector<int> v = {1,2,3,4,3,5};
    int dup = findDuplicate(v);
    cout<<findDuplicate(v)<<endl;
    return 0;
}