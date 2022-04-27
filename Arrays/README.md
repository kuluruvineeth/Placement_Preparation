# List of Standard Array Questions for Interview Preparations

## 1. [Finding the Duplicate Element in Array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/duplicate_number.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

/*There are three approaches to solve this problem in order of their efficiency
1.NAIVE APPROACH : sort the array and then do linear traversal if a[i]=a[i+1]
2.BETTER APPROACH : use count sort (maintain frequency array if any index is 2 that is dupicate number)
3.OPTIMAL APPROACH : linked list cycle method(Tortoise method)- two pointers method

*/

//1.NAIVE APPROACH : TIME=O(NLOGN),SPACE=O(1)

void duplicate_naive(vector<int> &v, int n)
{
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    if (v[i] == v[i + 1])
    {
      cout << "duplicate element is : " << v[i] << endl;
      break;
    }
    else
    {
      continue;
    }
  }
}

//2.BETTER APPROACH : TIME=O(N),SPACE=O(N)

void duplicate_better(vector<int> &v, int n)
{
  int f[n + 1];
  for (int i = 0; i <= n; i++)
  {
    f[i] = 0;
  }
  for (int i = 0; i <= n; i++)
  {
    f[v[i]]++;
  }

  for (int i = 1; i <= n; i++)
  {
    if (f[i] > 1)
    {
      cout << "duplicate element is : " << i << endl;
      break;
    }
    else
    {
      continue;
    }
  }
}

//3.OPTIMAL APPROACH : TIME=O(N),SPACE=O(1)

void duplicate_optimal(vector<int> &v, int n)
{
  int slow = v[0];
  int fast = v[0];

  do
  {
    slow = v[slow];
    fast = v[v[fast]];
  } while (slow != fast);

  fast = v[0];
  while (slow != fast)
  {
    slow = v[slow];
    fast = v[fast];
  }
  cout << "duplicate element is : " << v[slow] << endl;
}

//4.OPTIMAL APPROACH : one more simple optimal approach
void find_duplicate(vector<int> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    v[v[i] % n] = v[v[i] % n] + n;
  }
  for (int i = 0; i < n; i++)
  {
    if (v[i] / n > 1)
    {
      cout << "duplicate element is : " << i << endl;
    }
  }
}

int main()
{
  vector<int> v = {1, 3, 2, 4, 5, 6, 3};
  int n = v.size();
  //duplicate_naive(v,n);
  //duplicate_better(v,n);
  //duplicate_optimal(v,n);
  find_duplicate(v, n);
}
```

## 2. [Finding Peak Element in Array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/peak_element.cpp)
/*
Question : Given an array A of N integers. The task is to find a peak element in A in O( log N ) .
An array element is peak if it is not smaller than its neighbours. For corner elements, consider only one neighbour.

Example 1:

Input:
N = 3
A[] = {1,2,3}
Output: 2 
Explanation: In the given array, 
3 is the peak element as it is 
greater than its neighbour.
*/

#include<bits/stdc++.h>
using namespace std;

// peakElement Function using Binary Search method
int peakElement(int arr[], int n)
{
    int low=0, high=(n-1),mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if((mid > 0 && mid<(n-1) && arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) || (mid==0 && arr[mid]>=arr[mid+1]) || (mid==(n-1) && arr[mid]>=arr[mid-1]))
        {
            return mid;
        }
        else if(arr[mid+1]>=arr[mid])
        {
            low=(mid+1);
        }
        else if(arr[mid-1]>=arr[mid])
        {
            high=(mid-1);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int result = peakElement(a,n);
        cout<<"The peak element is : "<< a[result]<<endl;
        return 0;
    }
}
