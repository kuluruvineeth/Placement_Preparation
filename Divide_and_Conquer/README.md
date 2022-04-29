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

## 3. [Quick sort](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Divide_and_Conquer/quick_sort.cpp)
```cpp
/*
QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 

Always pick first element as pivot.
Always pick last element as pivot (implemented below)
Pick a random element as pivot.
Pick median as pivot.
The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
*/
#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int r)
{
    int pivot = a[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            int temp;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp;
    i++;
    temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return i;
}

void quick_sort(int a[],int l,int r)
{
    if(l<r)
    {
        int pindex = partition(a,l,r);
        quick_sort(a,l,pindex-1);
        quick_sort(a,pindex+1,r);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
```

## 4. [Merge sort](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Divide_and_Conquer/merge_sort.cpp)
```cpp
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
```

## 5. [Kth element in two sorted arrays](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Divide_and_Conquer/kth_element_in_two_sorted_arrays.cpp)
```cpp
/*
Given two sorted arrays of size m and n respectively, you are tasked with finding the element that would be at the k’th position of the final sorted array.

Examples: 

Input : Array 1 - 2 3 6 7 9
        Array 2 - 1 4 8 10
        k = 5
Output : 6
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n],b[m];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }
        int i=0,j=0,idx=0,ans;
        while(i<n && j<m && idx<k)
        {
            if(a[i] < b[j])
            {
                ans = a[i++];
                idx++;
            }
            else
            {
                ans = b[j++];
                idx++;
            }
        }
        while(i<n && idx<k)
        {
            ans = a[i++];
            idx++;
        }
        while(j<m && idx<k)
        {
            ans = b[j++];
            idx++;
        }
        cout<<ans<<endl;
    }
}
```