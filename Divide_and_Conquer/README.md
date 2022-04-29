# List of Divide and Conquer related questions for Interview Preparations

## 1. [Binary search iterative](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Divide_and_Conquer/binary_search_iterative.cpp)
```cpp
/*
Problem: Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].

Examples: 

Input: arr[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170}, x = 110
Output: 6
*/
#include<bits/stdc++.h>
using namespace std;


//Binary search : TIME = O(LOGN)  SPACE = O(1)


int binary_search(vector<int> &v,int low,int high,int element)
{
	while(low<=high)
	{	
		int mid =low + (high-low)/2;
		
		if(v[mid]==element)
		{
			return mid;
		}

		else if(v[mid]>element)
		{
			high=mid-1;
		}

		else
		{
			low=mid+1;
		}
	}
	return -1;
}


int main()
{
	vector<int> v={1,2,3,4,5};
	int n=v.size();
	int loc = binary_search(v,0,n-1,4);
	if(loc==-1)
	{
		cout<<"Element not found " <<endl;
	}
	else
	{
		cout<<"Element found at location : "<<loc<<endl;
	}
	return 0;
}
```

## 2. [Binary search recursive](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Divide_and_Conquer/binary_search_recursive.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int binary_search_recursive(int a[],int l,int r,int x)
{
    if(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        else if(a[mid]>x)
        {
            return binary_search_recursive(a,l,mid-1,x);
        }
        else
        {
            return binary_search_recursive(a,mid+1,r,x);
        }
    }
    return -1;
}

int main()
{
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    int idx = binary_search_recursive(a,0,n-1,x);
    if(idx==-1)
    {
        cout<<"Element not found!"<<endl;
    }
    else
    {
        cout<<"Element found at index "<<idx+1<<endl;
    }
}
```