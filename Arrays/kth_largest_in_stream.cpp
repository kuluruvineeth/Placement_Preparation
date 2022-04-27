/*
Given an infinite stream of integers, find the k’th largest element at any point of time.
Example: 

Input:
stream[] = {10, 20, 11, 70, 50, 40, 100, 5, ...}
k = 3

Output:    {_,   _, 10, 11, 20, 40, 50,  50, ...}
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int k,n;
        cin>>k>>n;
        int a[n];
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i<k-1)
            {
                pq.push(a[i]);
                cout<<-1<<" ";
            }
            else
            {
                pq.push(a[i]);
                int x = k-1;
                vector<int> v;
                while(x--)
                {
                    v.push_back(pq.top());
                    pq.pop();
                }
                cout<<pq.top()<<" ";
                for(int j=0;j<v.size();j++)
                {
                    pq.push(v[j]);
                }
            }
        }
        cout<<endl;
    }
}