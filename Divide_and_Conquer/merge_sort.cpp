/*
 Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then it merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one
 */
#include<bits/stdc++.h>
using namespace std;


//MERGE SORT : TIME = O(N*LOGN) , SPACE = O(N)


//merge function
void merge(vector<int> &v,int low,int mid,int high)
{
	int n1 = mid -low + 1;
	int n2 = high - mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
	{
		left[i]=v[low+i];
	}

	for(int j=0;j<n2;j++)
	{
		right[j]=v[mid+j+1];
	}

	int i=0,j=0,k=low;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			v[k]=left[i];
			i++;
		}
		else
		{
			v[k]=right[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		v[k]=left[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		v[k]=right[j];
		j++;
		k++;
	}
}
		



//merge sort function
void mergesort(vector<int> &v,int low,int high)
{
	if(low<high)
	{
		int mid = low + (high-low)/2;
		mergesort(v,low,mid);
		mergesort(v,mid+1,high);
		merge(v,low,mid,high);
	}
}

int main()
{
	vector<int> v={3,15,18,8,12,21,6,16};
	int n=v.size();
	mergesort(v,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}