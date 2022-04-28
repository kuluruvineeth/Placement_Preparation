/*
Write a program to print all the LEADERS in the array. An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader. For example in the array {16, 17, 4, 3, 5, 2}, leaders are 17, 5 and 2
*/

#include<bits/stdc++.h>
using namespace std;

/*There are two approaches to solve this problem in order of their efficiency
1.Naive approach : Take two loops i.e for each element compare with other elements of array
2.Optimal approach : Here traverse from end of the array to start point,if current element is greater than max from right then we will print that and update max value.
*/

//1.NAIVE APPROACH : TIME : O(N^2) , SPACE : O(1)
void leaders_naive(vector<int> &v, int n)
{
    int leaders=0,j;
    for(int i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(v[i]<v[j])
            {
                break;
            }
        }
        if(j==n)
        {
            cout<<v[i]<<endl;
        }
    }
    cout<<endl;
}

//2.OPTIMAL APPROACH : TIME : O(N) ,SPACE : O(1)
void leaders_optimal(vector<int> &v,int n)
{
    int max=v[n-1];
    cout<<max<<endl;
    for(int i=n-2;i>=0;i--)
    {
        if(v[i]>max)
        {
            cout<<v[i]<<endl;
            max = v[i];
        }
        else
        {
            continue;
        }
    }
    cout<<endl;
}

int main()
{
    vector<int> v={16,17,4,35,2};
    int n=v.size();
    leaders_naive(v,n);
    leaders_optimal(v,n);
    return 0;
}