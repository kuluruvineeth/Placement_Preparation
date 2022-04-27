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

