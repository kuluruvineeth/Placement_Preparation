# List of Math based questions fro interview preparation

## 1. [Next Similar Number](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Math/next_similar_number.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int num(char c)
{
    return c - '0';
}
void reverse(string&A,int i,int j)
{
    while(i<j)
    {
        swap(A[i],A[j]);
        i++;
        j--;
    }
}
string nextSimilarNumber(string A)
{
    int i;
    int n=A.size();
    for(i=n-2;i>=0;i--)
    {
        if(num(A[i])<num(A[i+1])) break;
    }
    //already the maximum number
    if(i==-1) return "-1";
    //replace this number with greatest right most number
    int j=n-1;
    for(;j>i;j--)
    {
        if(num(A[j])>num(A[i])) break;
    }
    //swap with this number
    swap(A[j],A[i]);
    //remaining numbers from A[i+1] to A[j]
    reverse(A,i+1,n-1);
    return A;
}

int main()
{
    string s= "218765";
    cout<<nextSimilarNumber(s)<<endl;
    return 0;
}
```

## 2. [Grid Unique Paths](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Interviewbit/Math/grid_unique_paths.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int m,int n)
{
    if(m==1 || n==1) return 1;
    return uniquePaths(m-1,n) + uniquePaths(m,n-1);
}

int main()
{
    cout<<uniquePaths(3,3)<<endl;
    return 0;
}
```