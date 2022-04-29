/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Examples:  

Input: arr[]   = {2, 0, 2}
Output: 2
*/
#include<bits/stdc++.h>
using namespace std;

/*There are 4 to 5 approaches to solve this problem in order of their complexity
1.Naive Approach : At every point find its maximum left and maximum right and find difference between current height and and minimum of max(left,right)
2.Better Approach : Take two extra arrays , for one array traverse from left to right till end to store maximum at each point ,other array from right to left store maximum at each point from right end.Now linearly traverse array by storing min(left[i],right[i]) - v[i].
3.Optimal approach : Here instead of maintaining two arrays we are storing leftmax and rightmax till that point and we performing our normal formula.
*/

//1.Naive approach : TIME : O(N^2) , SPACE : O(1)

void trap_naive(vector<int> &v,int n)
{
	int amount_of_water=0;
	for(int i=0;i<n;i++)
	{
		int left=v[i];
		for(int j=0;j<i;j++)
		{
			left=max(left,v[j]);
		}
		int right=v[i];
		for(int j=i+1;j<n;j++)
		{
			right=max(right,v[j]);
		}
		amount_of_water+=abs(v[i] - min(left,right));
	}
	cout<<"Amount of water that can be trapped is : "<<amount_of_water<<endl;
}

//2.Better approach : TIME : O(N) , SPACE : O(N)
void trap_better(vector<int> &v,int n)
{
	int amount_of_water=0;
	vector<int> l(n),r(n);

	l[0]=v[0];
	for(int i=1;i<n;i++)
	{
		l[i]=max(l[i-1],v[i]);
	}

	r[n-1]=v[n-1];
	for(int i=n-2;i>=0;i--)
	{
		r[i]=max(r[i+1],v[i]);
	}

	for(int i=0;i<n;i++)
	{
		amount_of_water+=(min(l[i],r[i]) - v[i]);
	}
	cout<<"Amount of water that trapped is : "<<amount_of_water<<endl;
}

//3.Optimal approach : TIME : O(N) , SPACE : O(1)
void trap_optimal(vector<int> &v ,int n)
{
	int l=0,r=n-1;
	int lmax=0,rmax=0;
	int amount_of_water=0;
	while(l<=r)
	{
		if(v[l]<v[r])
		{
			if(v[l]>lmax)
			{
				lmax=v[l];
			}
			else
			{
				amount_of_water+=lmax-v[l];
			}
			l++;
		}
		else
		{
			if(v[r]>rmax)
			{
				rmax=v[r];
			}
			else
			{
				amount_of_water+=rmax-v[r];
			}
			r--;
		}
	}
	cout<<"Amount of water that is trapped is : "<<amount_of_water<<endl;
}

int main()
{
	vector<int> v={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n=v.size();
	trap_naive(v,n);
	trap_better(v,n);
	trap_optimal(v,n);
	return 0;
}