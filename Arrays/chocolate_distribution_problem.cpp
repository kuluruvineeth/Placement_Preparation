/*
Given an array of n integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that: 

Each student gets one packet.
The difference between the number of chocolates in the packet with maximum chocolates and packet with minimum chocolates given to the students is minimum.
Examples:

Input : arr[] = {7, 3, 2, 4, 9, 12, 56} , m = 3 
Output: Minimum Difference is 2 
Explanation:
We have seven packets of chocolates and 
we need to pick three packets for 3 students 
If we pick 2, 3 and 4, we get the minimum 
difference between maximum and minimum packet 
sizes.

Input : arr[] = {3, 4, 1, 9, 56, 7, 9, 12} , m = 5 
Output: Minimum Difference is 6 
Explanation:
The set goes like 3,4,7,9,9 and the output 
is 9-3 = 6
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;
        int a[n];
        int mn=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>k;
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if((i+k-1) < n && (a[i+k-1] - a[i]) < mn)
            {
                mn = a[i+k-1] - a[i];
            }
        }
        cout<<mn<<endl;
    }
}