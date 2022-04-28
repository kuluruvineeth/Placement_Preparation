/*
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in the list. One of the integers is missing in the list. Write an efficient code to find the missing integer.
Example: 

Input: arr[] = {1, 2, 4, 6, 3, 7, 8}
Output: 5
Explanation: The missing number from 1 to 8 is 5
*/
/*There are three appraoches to solve this problem in order of their efficiency
1.NAIVE APPROACH : count sort techinque(maintaining the frequency array)
2.BETTER APPROACH : (sum of first n natural numbers - sum of the array) gives missing number
3.OPTIMAL APPROACH : XOR method(Xor between first n numbers and given array)
*/
#include<bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH : TIME=O(N),SPACE=O(N)
void missing_naive(vector<int> &v, int n)
{
    int f[n+1];
    for(int i=0;i<=n;i++)
    {
        f[i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        f[v[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            cout<<"missing number is : "<<i<<endl;
        }
        else
        {
            continue;
        }
    }
}

//2.BETTER APPRAOCH : TIME=O(N),SPACE=O(1),Overflow problem can occur
void missing_better(vector<int> &v,int n)
{
	int sum=(n+1)*(n+2)/2;
	for(int i=0;i<n;i++)
	{
		sum-=v[i];
	}
	cout<<"missing number is : "<<sum<<endl;
}

//3.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1),No overflow problem
void missing_optimal(vector<int> &v,int n)
{
    int x1=v[0];
    int x2=1;

    for(int i=1;i<n;i++)
    {
        x1=x1^v[i];
    }
    for(int i=2;i<=n+1;i++)
    {
        x2=x2^i;
    }
    cout<<"missing number is : "<<(x1^x2)<<endl;
}

int main()
{
    vector<int> v{1, 2, 4, 6, 3, 7, 8};
    int n=v.size();
    missing_naive(v,n);
    missing_better(v,n);
    missing_optimal(v,n);
}