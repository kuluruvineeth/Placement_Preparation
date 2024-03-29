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
```cpp
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
```

## 3. [Finding Sub Array with Max Sum - Kadane's Algorithm](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/max_subarray_kadanes.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

/*There are three approaches to solve this problem,but here i use only two methods
1.BETTER APPROACH : two loops method
2.OPTIMAL APPROACH : kadane's algorithm

*/

//1.BETTER APPROACH : TIME=O(N^2),SPACE=O(1)

void max_subarray_sum_better(vector<int> &v, int n)
{
  int max = 0;
  int maxi = 0;
  int maxj = -1;
  int sum;
  for (int i = 0; i < n; i++)
  {
    sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += v[j];
      if (sum > max)
      {
        max = sum;
        maxi = i;
        maxj = j;
      }
    }
  }
  for (int i = maxi; i <= maxj; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
  cout << "maximum subarray sum is : " << max << endl;
}

//2.OPTIMAL APPROACH: TIME=O(N),SPACE=O(1)
void max_subarray_sum_optimal(vector<int> &v, int n)
{
  int sum = 0, maxsum = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    sum += v[i];
    maxsum = max(sum, maxsum);
    if (sum < 0)
    {
      sum = 0;
    }
  }
  cout << "maximum subarray sum is : " << maxsum << endl;
}

int main()
{
  vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
  int n = v.size();
  //max_subarray_sum_better(v, n);
  max_subarray_sum_optimal(v, n);
  return 0;
}
```

## 4. [Element with left side smaller and right side greater](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/Element_with_left_side_smaller_and_right_side_greater.cpp)
```cpp
/*
Question - Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Example : 
Input:
N = 4
A[] = {4, 2, 5, 7}
Output:
5
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int flag=0,left[n],right[n];
        left[0] = a[0];
        right[n-1] = a[n-1];
        for(int i=1;i<n;i++)
        {
            left[i] = max(a[i],left[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            right[i] = min(a[i],right[i+1]);
        }
        for(int i=1;i<=n-2;i++)
        {
            if(a[i] >= left[i] && a[i] <= right[i])
            {
                cout<<a[i]<<endl;
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
        }
    }
}
```

## 5. [Kth largest in stream](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/kth_largest_in_stream.cpp)
```cpp
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
```

## 6. [Merging without extra space](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/merge_less_space.cpp)
```cpp
// /* PROBLEM STATEMENT : Given two sorted arrays merge them without using extra space*/

// /*There are three approaches to solve this problem.Approaches are in increasing order of their efficiency
// 1.NAIVE APPROACH : copy both elements in one single array and then sort and place back.
// 2.BETTER APPROACH : like insertion sorting
// 3.OPTIMAL APPROACH : GAP method(intuition of shell sort)
// */

// #include <bits/stdc++.h>
// using namespace std;

// //1.NAIVE APPROACH : TIME=O(NLOGN) + O(N) + O(N),SPACE=O(N)
// void merge_naive(vector<int> &v1, int n, vector<int> &v2, int m)
// {
//   vector<int> v;
//   for (int i = 0; i < n; i++)
//   {
//     v.push_back(v1[i]);
//   }
//   for (int i = 0; i < m; i++)
//   {
//     v.push_back(v2[i]);
//   }
//   for (int i = 0; i < n + m; i++)
//   {
//     cout << v[i] << " ";
//   }
//   cout << endl;
//   sort(v.begin(), v.end());

//   for (int i = 0; i < n; i++)
//   {
//     v1[i] = v[i];
//   }

//   for (int i = 0; i < m; i++)
//   {
//     v2[i] = v[n + i];
//   }

//   for (int i = 0; i < n; i++)
//   {
//     cout << v1[i] << " ";
//   }
//   cout << endl;
//   for (int i = 0; i < m; i++)
//   {
//     cout << v2[i] << " ";
//   }
//   cout << endl;
// }

// //2.BETTER APPROACH : TIME=O(N*M),SPACE=O(1)
// void merge_better(vector<int> &v1, int n, vector<int> &v2, int m)
// {
//   for (int i = 0; i < n; i++)
//   {
//     if (v1[i] > v2[0])
//     {
//       swap(v1[i], v2[0]);
//       int j = 0;
//       while ((j + 1) < m and v2[j] > v2[j + 1])
//       {
//         swap(v2[j], v2[j + 1]);
//         j++;
//       }
//     }
//   }
//   for (int i = 0; i < n; i++)
//   {
//     cout << v1[i] << " ";
//   }
//   cout << endl;
//   for (int i = 0; i < m; i++)
//   {
//     cout << v2[i] << " ";
//   }
//   cout << endl;
// }

// int nextgap(int gap)
// {
//   if (gap <= 1)
//   {
//     return 0;
//   }
//   return (gap / 2) + (gap % 2);
// }

// //3.OPTIMAL APPROACH: TIME=O(NLOGN),SPACE=O(1)
// void merge_optimal(vector<int> &v1, int n, vector<int> &v2, int m)
// {
//   int i, j, gap = n + m;
//   for (gap = nextgap(gap); gap > 0; gap = nextgap(gap))
//   {
//     //comparing elements in first array
//     for (int i = 0; i + gap < n; i++)
//     {
//       if (v1[i] > v1[i + gap])
//       {
//         swap(v1[i], v1[i + gap]);
//       }
//     }

//     //comparing elements in both arrays
//     for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++)
//     {
//       if (v1[i] > v2[j])
//       {
//         swap(v1[i], v2[j]);
//       }
//     }

//     if (j < m)
//     {
//       // comparing elements in the second array
//       for (j = 0; j + gap < m; j++)
//       {
//         if (v2[j] > v2[j + gap])
//         {
//           swap(v2[j], v2[j + gap]);
//         }
//       }
//     }
//   }

//   for (int i = 0; i < n; i++)
//   {
//     cout << v1[i] << " ";
//   }
//   cout << endl;
//   for (int i = 0; i < m; i++)
//   {
//     cout << v2[i] << " ";
//   }
//   cout << endl;
// }

// int main()
// {
//   vector<int> v1{1, 4, 7, 8, 10};
//   int n = v1.size();
//   vector<int> v2{2, 3, 9};
//   int m = v2.size();
//   //merge_naive(v1, n, v2, m);
//   //merge_better(v1, n, v2, m);
//   merge_optimal(v1, n, v2, m);
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int nextGap(int gap)
{
  if (gap <= 1)
    return 0;
  return (gap / 2) + (gap % 2);
}
void merge(int arr1[], int arr2[], int n, int m)
{
  int i, j, gap = n + m;
  for (gap = nextGap(gap);
       gap > 0; gap = nextGap(gap))
  {
    // comparing elements in the first array.
    for (i = 0; i + gap < n; i++)
      if (arr1[i] > arr1[i + gap])
        swap(arr1[i], arr1[i + gap]);

    // comparing elements in both arrays.
    for (j = gap > n ? gap - n : 0;
         i < n && j < m;
         i++, j++)
      if (arr1[i] > arr2[j])
        swap(arr1[i], arr2[j]);

    if (j < m)
    {
      // comparing elements in the second array.
      for (j = 0; j + gap < m; j++)
        if (arr2[j] > arr2[j + gap])
          swap(arr2[j], arr2[j + gap]);
    }
  }
}

// { Driver Code Starts.

int main()
{

  int T;
  cin >> T;

  while (T--)
  {
    int n, m;
    cin >> n >> m;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
    {
      cin >> arr1[i];
    }

    for (int i = 0; i < m; i++)
    {
      cin >> arr2[i];
    }

    merge(arr1, arr2, n, m);

    for (int i = 0; i < n; i++)
      printf("%d ", arr1[i]);

    for (int i = 0; i < m; i++)
      printf("%d ", arr2[i]);

    cout << endl;
  }

  return 0;
}
```

## 7. [Two stacks in an array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/two_stacks_in_an_array.cpp)
```cpp
/*
task is to implement  2 stacks in one array efficiently .

Example 1:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()
Output:
3 4 -1
*/

#include<bits/stdc++.h>
using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;

    public:
        twoStacks(int n=100)
        {
            size = n;
            arr= new int[n];
            top1 = -1;
            top2 = size;
        }
        void push1(int x);
        void push2(int x);
        int pop1();
        int pop2();
};

void twoStacks :: push1(int x)
{
    arr[++top1]=x;
}

void twoStacks :: push2(int x)
{
    arr[--top2]=x;
}

int twoStacks :: pop1()
{
    if(top1==-1)
    {
        return -1;
    }
    return arr[top1--];
}

int twoStacks :: pop2()
{
    if(top2==size) return -1;
    return arr[top2++];
}

int main()
{
    int T;
    cin>> T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>> Q;
        while(Q--)
        {
            int stack_no;
            cin>>stack_no;
            int QueryType=0;
            cin>>QueryType;

            if(QueryType==1)
            {
                int a;
                cin>>a;
                if(stack_no ==1)
                {
                    sq->push1(a);
                }
                else if(stack_no=2)
                {
                    sq->push2(a);
                }
            }
            else if(QueryType==2)
            {
                if(stack_no==1)
                {
                    cout<<sq->pop1();
                }
                else if(stack_no==2)
                {
                    cout<<sq->pop2()<<" ";
                }
            }
        }
        cout<<endl;
    }
}
```

## 8. [Union of two sorted arrays](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/union_of_two_sorted_arrays.cpp)
```cpp
/*
Given two sorted arrays arr[] and brr[] of size N and M respectively. The task is to find the union of these two arrays.
Union of two arrays can be defined as the common and distinct elements in the two arrays.

Example 1:

Input: 
N = 5, arr1[] = {1, 2, 3, 4, 5}  
M = 3, arr2 [] = {1, 2, 3}
Output: 1 2 3 4 5
Explanation: Distinct elements including 
both the arrays are: 1 2 3 4 5.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[],int arr2[],int n, int m)
{
    vector<int> ans;
    int i=0,j=0;
    if(arr1[i]>arr2[j])
    {
        ans.push_back(arr2[j]);
        j++;
    }
    else if(arr1[i]<arr2[j])
    {
        ans.push_back(arr1[i]);
        i++;
    }
    else
    {
        ans.push_back(arr1[i]);
        i++;
        j++;
    }
    while(i<n && j<m)
    {
        if(arr1[i]==ans.back() && i>=0)
        {
            i++;
            continue;
        }
        if(arr2[j]==ans.back() && j>=0)
        {
            j++;
            continue;
        }
        if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j])
        {
            ans.push_back(arr2[j]);
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while(i<n)
    {
        if(arr1[i]!=ans.back())
        {
            ans.push_back(arr1[i]);
            i++;
        }
    }
    while(j<m)
    {
        if(arr2[j]!=ans.back())
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int N,M;
        cin>>N>>M;
        int arr1[N],arr2[M];

        for(int i=0;i<N;i++)
        {
            cin>> arr1[i];
        }

        for(int i=0;i<M;i++)
        {
            cin>>arr2[i];
        }
        vector<int> ans = findUnion(arr1,arr2,N,M);
        for(int i:ans)
        {
            cout<<i<<endl;
        }
        cout<<endl;
    }
}
```

## 9. [Array zig-zag](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/array_zig_zag.cpp)
```cpp
/*
Given an array of DISTINCT elements, rearrange the elements of array in zig-zag fashion in O(n) time. The converted array should be in form a < b > c < d > e < f. 

Example:

Input: arr[] = {4, 3, 7, 8, 6, 2, 1} 
Output: arr[] = {3, 7, 4, 8, 2, 6, 1}

Input: arr[] = {1, 4, 3, 2} 
Output: arr[] = {1, 4, 2, 3}
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++)
        {
            if(i%2 == 0)
            {
                if(a[i] > a[i+1])
                {
                    int temp;
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
            else
            {
                if(a[i] < a[i+1])
                {
                    int temp;
                    temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
        cout<<endl;
    }
}
```

## 10. [Chocolate distribution problem](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/chocolate_distribution_problem.cpp)
```cpp
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
```

## 11. [Equilibrium point in array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/equilibrium_point.cpp)
```cpp
/*
Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that the sum of elements before it is equal to the sum of elements after it.
*/

#include<bits/stdc++.h>
using namespace std;

int equilibrium_point(int a[],int n)
{
    int sum=0,leftsum=0,rightsum;

    for(int i=0;i<n;i++)
    {
        sum += a[i];
    }
    rightsum = sum;
    for(int i=0;i<n;i++)
    {
        rightsum -= a[i];
        if(leftsum == rightsum)
        {
            return i+1;
        }
        leftsum += a[i];
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<equilibrium_point(a,n)<<endl;
}
```

## 12. [Find element that appears once](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/find_element_that_appears_once.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            ans = ans^a[i];
        }
        cout<<ans<<endl;
    }
}
```

## 13. [Kth smallest element](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/kth_smallest.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            pq.push(a[i]);
        }
        int k;
        cin>>k;
        while(k--)
        {
            pq.pop();
        }
        cout<<pq.top()<<endl;
    }
}
```

## 14. [Largest number formed from array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/largest_number_formed_from_array.cpp)
```cpp
//TIME : O(N*LOGN) , SPACE : O(1)
#include<bits/stdc++.h>
using namespace std;

int cmp(string a, string b)
{
    string ab = a+b;
    string ba = b+a;
    if(ab > ba)
    {
        return 1;
    }
    else
    {
        return 0;
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
        string s[n];
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }
        sort(s,s+n,cmp);
        for(int i=0;i<n;i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}
```

## 15. [Leaders in an array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/leaders_in_an_array.cpp)
```cpp
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
```

## 16. [Maximum sum increasing subsequence](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/maximum_sum_increasing_subsequence.cpp)
```cpp
/*
The Maximum Sum Increasing Subsequence problem is to find the maximum sum subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

Examples: 

Input:  [1, 101, 2, 3, 100, 4, 5]
Output: [1, 2, 3, 100]

Input:  [3, 4, 5, 10]
Output: [3, 4, 5, 10]
*/
#include<bits/stdc++.h>
using namespace std;

int maximum_sum_increasing_subsequence(int a[],int n)
{
    int mx=-1;
    int dp[n+1];
    for(int i=0;i<n;i++)
    {
        dp[i] = a[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && a[i]+dp[j] > dp[i])
            {
                dp[i] = a[i] + dp[j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        mx = max(mx,dp[i]);
    }
    return mx;
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
        cout<<maximum_sum_increasing_subsequence(a,n)<<endl;
    }
}
```

## 17. [Missing number in an array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/missing_number_in_an_array.cpp)
```cpp
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
```

## 18. [Pythagorean triplet](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/pythagorean_triplet.cpp)
```cpp
/*
Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

Example: 

Input: arr[] = {3, 1, 4, 6, 5} 
Output: True 
There is a Pythagorean triplet (3, 4, 5)
*/
#include<bits/stdc++.h>
using namespace std;

bool isTriplet(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = arr[i]*arr[i];
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=2;i--)
    {
        int l=0,r=i-1;
        while(l<r)
        {
            if((arr[l]+arr[r]) == arr[i])
            {
                return true;
            }
            (arr[l] + arr[r] < arr[i])? l++:r--;
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        isTriplet(arr,n)? cout<<"Yes": cout<<"No";
        cout<<endl;
    }
    return 0;
}
```

## 19. [Reverse in groups](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/reverse_in_group.cpp)
```cpp
/*
Given an array, reverse every sub-array formed by consecutive k elements.

Examples: 

Input: 
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9] 
k = 3 
Output: 
[3, 2, 1, 6, 5, 4, 9, 8, 7]
*/
#include<bits/stdc++.h>
using namespace std;

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
        int k;
        cin>>k;
        for(int i=0;i<n;i+=k)
        {
            int l=i;
            int r=min(i+k-1,n-1);
            while(l<r)
            {
                swap(a[l++],a[r--]);
            }
        }
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}
```

## 20. [Sort 0s1s2s](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/sort0s1s2s.cpp)
```cpp
#include <bits/stdc++.h>
using namespace std;

/* PROBLEM STATEMENT : Given an array of 0s,1s and 2s sort the array without using sort algorithm*/

/*There are three approaches to solve this problem.Approches are in increasing order of their efficiency
1.NAIVE APPROACH : just sort with sort function
2.BETTER APPROACH : use count sort(two traversals)
3.OPTIMAL APPROACH : Dutch National Flag Algorithm(using three pointers)

*/

//1.NAIVE APPROACH : TIME=O(NLOGN), SPACE=O(1)
void sortnaive(vector<int> &v, int n)
{
  //sort algorithm
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

//2.BETTER APPROACH : TIME=O(N), SPACE=O(1)

void sortbetter(vector<int> &v, int n)
{
  int count0 = 0, count1 = 0, count2 = 0;
  int i = 0;
  while (i < n)
  {
    switch (v[i])
    {
    case 0:
      count0++;
      break;

    case 1:
      count1++;
      break;

    case 2:
      count2++;
      break;
    default:
      exit(1);
    }
    i++;
  }

  i = 0;
  while (count0 > 0)
  {
    v[i++] = 0;
    count0--;
  }
  while (count1 > 0)
  {
    v[i++] = 1;
    count1--;
  }

  while (count2 > 0)
  {
    v[i++] = 2;
    count2--;
  }

  for (int j = 0; j < n; j++)
  {
    cout << v[j] << " ";
  }
  cout << endl;
}

//3.OPTIMAL APPROACH : TIME=O(N) , SPACE=O(1)

void sortoptimal(vector<int> &v, int n)
{
  int low = 0;
  int mid = 0;
  int high = n - 1;
  while (mid <= high)
  {
    switch (v[mid])
    {
    case 0:
      swap(v[mid++], v[low++]);
      break;
    case 1:
      mid++;
      break;
    case 2:
      swap(v[mid], v[high--]);
      break;
    default:
      exit(1);
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> v{0, 1, 2, 1, 2, 0, 1, 2};
  int n = v.size();
  sortnaive(v, n);
  sortbetter(v,n);
  sortoptimal(v,n);
}
```

## 21. [Sprial matrix](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/spiral_matrix.cpp)
```cpp
/*
Given a 2D array, print it in spiral form. See the following examples.

Examples: 

Input:  {{1,    2,   3,   4},
              {5,    6,   7,   8},
             {9,   10,  11,  12},
            {13,  14,  15,  16 }}
Output: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r=4,c=4;
        int a[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        int k=0,l=0;
        while(k<r && l<c)
        {
            for(int i=l;i<c;i++)
            {
                cout<<a[k][i]<<" ";
            }
            k++;
            for(int i=k;i<r;i++)
            {
                cout<<a[i][c-1]<<" ";
            }
            c--;
            if(k<r)
            {
                for(int i=c-1;i>=l;i--)
                {
                    cout<<a[r-1][i]<<" ";
                }
                r--;
            }
            if(l<c)
            {
                for(int i=r-1;i>=k;i--)
                {
                    cout<<a[i][l]<<" ";
                }
                l++;
            }
        }
    }
}
```

## 22. [Buy stock sell](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/buy_stock_sell.cpp)
```cpp
/* PROBLEM STATEMENT: Given an array of stock prices,find maximum profit we can make with one transaction*/

/*There are two approaches to solve this problem.Approaches are in increasing order of their efficiency
1.NAIVE APPROACH : using two loops
2.OPTIMAL APPROACH : DP approach
*/

#include <bits/stdc++.h>
using namespace std;

//1.NAIVE APPROACH: TIME=O(N^2),SPACE=O(1)
void profit_naive(vector<int> &v, int n)
{
  int max_profit = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    int costprice = v[i];
    int maxi = INT_MIN;
    for (int j = i + 1; j < n; j++)
    {
      if (v[j] > costprice)
      {
        maxi = max(maxi, v[j]);
      }
    }
    int profit = 0;
    if (maxi != INT_MIN)
    {
      profit = maxi - costprice;
    }
    max_profit = max(max_profit, profit);
  }
  cout << "The maximum profit is : " << max_profit << endl;
}

//2.OPTIMAL APPROACH: TIME=O(N),SPACE=O(1)
void profit_optimal(vector<int> &v, int n)
{
  int max_profit = 0;
  int min_price = INT_MAX;
  for (int i = 0; i < n; i++)
  {
    min_price = min(min_price, v[i]);
    max_profit = max(max_profit, v[i] - min_price);
  }
  cout << "The maximum profit is : " << max_profit << endl;
}

int main()
{
  vector<int> v{7, 1, 5, 3, 6, 4};
  int n = v.size();
  //profit_naive(v, n);
  profit_optimal(v, n);
  return 0;
}
```

## 23. [Trapping Rain Water](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Arrays/trapping_rain_water.cpp)
```cpp
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
```

