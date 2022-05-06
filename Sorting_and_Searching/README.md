# List of Sorting and Searching questions for Interview Preparation

## 1. [First pos and Last pos](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/first_pos_and_last_pos.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<int> find(int arr[],int n,int x)
{
    int low=0,high=n-1,first_occ=-1,last_occ=-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>x)
        {
            high = mid - 1;
        }
        else if(arr[mid]<x)
        {
            low = mid + 1;
        }
        // If arr[mid] is same as x, we
        // update res and move to the left
        // half.
        else
        {
            first_occ = mid;
            high = mid - 1;
        }
    }

    low = 0, high = n-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(arr[mid]>x)
        {
            high = mid - 1;
        }
        else if(arr[mid]<x)
        {
            low = mid + 1;
        }
        // If arr[mid] is same as x, we
        // update res and move to the right
        // half
        else
        {
            last_occ = mid;
            low = mid + 1;
        }
    }
    return {first_occ,last_occ};
}

int main()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> v = find(a,n,x);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
```

## 2. [Search in rotated sorted array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/search_in_rotated_sorted_array.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums,int target)
{
    int low=0,high=nums.size()-1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        else if(nums[mid]>=nums[low])
        {
            if(nums[low]<=target && nums[mid]>=target)
            {
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if(nums[mid]<=target && nums[high]>=target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<search(v,target)<<endl;
    return 0;
}
```

## 3. [Count squares](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/count_squares.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int countSquares(int n)
{
    int i=1;
    while((i*i)<n)
    {
        i++;
    }
    return i-1;
}

int main()
{
    int n;
    cin>>n;
    cout<<countSquares(n)<<endl;
    return 0;
}
```

## 4. [Middle element](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/max_min_with_min_comparison.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int middle(int A,int B,int C)
{
    if(A<B)
    {
        return (B<C) ? B : max(A,C);
    }
    return (A<C) ? A : max(B,C);
}

int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    cout<<middle(A,B,C)<<endl;
    return 0;
}
```

## 5. [Find repeating and missing](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/find_repeating_and_missing.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int *findTwoelement(int *arr,int n)
{
    int *ans = new int[2],i;

    //here we will keep alternating sign of the place to know which repeated.
    for(i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1] > 0)
        {
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
        }
        else
        {
            //here prev some no. made negative hence that no. is repeating
            ans[0] = abs(arr[i]);
        }
    }
    for(i=0;i<n;i++)
    {
        //if it is positive means nonw of the element was able to alternate sign.
        //hence that place is the missing ans
        if(arr[i]>0)
        {
            ans[1] = i+1;
        }
    }
    return ans;
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
    int* ans = new int[2];
    ans = findTwoelement(a,n);
    cout<<"Repeating : "<<ans[0]<<" Missing : "<<ans[1];
    return 0;
}
```

## 6. [Find Pair Difference](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/find_pair_with_given_diff.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[],int size,int n)
{
    sort(arr,arr+size);
    int i=0;
    int j=1;
    while(i<size && j<size)
    {
        if(i!=j && arr[j]-arr[i]==n)
        {
            return true;
        }
        else if(arr[j]-arr[i]<n)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int main()
{
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<findPair(a,n,d)<<endl;
    return 0;
}
```

## 7. [Merge 2 sorted arrays](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/merge_2sorted_arrays.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[],int arr2[],int m,int n)
{
    int i=0,j=0,k=m-1;
    //until i less than equal to k or j is less than m
    while(i<=k and j<n)
    {
        if(arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr2[j++],arr1[k--]);
        }
    }
    //sort first array
    sort(arr1,arr1+m);
    //sort second array
    sort(arr2,arr2+n);
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr1[m],arr2[n];
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }
    cout<<"After merging two sorted arrays : "<<endl;
    merge(arr1,arr2,m,n);
    for(int i=0;i<m;i++)
    {
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
}
```

## 8. [Subarrays with 0 sum](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/subarrays_with_0sum.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findSubArrays(int arr[],int n)
{
    //create an empty map
    unordered_map<int,vector<int>> map;
    // create an empty vector of pairs to store subarray starting and ending index
    vector<pair<int,int>> out;

    //maintains sum of elements so far
    int sum = 0;

    for(int i=0;i<n;i++)
    {
        //add current element to sum
        sum += arr[i];
        //if sum is 0, we found a subarray starting from index 0 and ending at index 1
        if(sum==0)
        {
            out.push_back(make_pair(0,i));
        }

        //if sum already exists in the map there exists
        //at-least one subarray ending at index i with 0 sum
        if(map.find(sum)!=map.end())
        {
            //map[sum] stores starting index of all subarrays
            vector<int> vc=map[sum];
            for(auto it=vc.begin();it!=vc.end();it++)
            {
                out.push_back(make_pair(*it+1,i));
            }
        }
        map[sum].push_back(i);
    }
    return out;
}

//Utility function to print all subarrays with sum 0
void print(vector<pair<int,int>> out)
{
    for(auto it=out.begin();it!=out.end();it++)
    {
        cout<<"Subarray found from Index "<<
        it->first << " to "<<it->second<<endl;
    }
}

int main()
{
    int arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int,int>> out = findSubArrays(arr,n);

    //if we didn't find any subarray with 0 sum
    //then subarray doesn't exists
    if(out.size() == 0)
    {
        cout<<"No subarray exists";
    }
    else
    {
        print(out);
    }
    return 0;
}
```

## 9. [Sort array acc to count set bits](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/sort_array_acc_to_count_set_bits.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

//utility function that returns total set bits count in an integer
int countBits(int a)
{
    int count = 0;
    while(a)
    {
        if(a&1)
        {
            count++;
        }
        a=a>>1;
    }
    return count;
}

//custom comparator of std::sort
int cmp(int a,int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
    
    //this takes care of the stability of sorting algorithm too
    if(count1<=count2)
    {
        return false;
    }
    return true;
}

//Function to sort according to bit count using std::sort
void sortBySetBitCount(int arr[],int n)
{
    stable_sort(arr,arr+n,cmp);
}

//utility function to print an array
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {5,2,3,9,4,6,7,15,32};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortBySetBitCount(arr,n);
    printArray(arr,n);
    return 0;
}
```

## 10. [Min swaps to sort array](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting_and_Searching/min_swaps_to_sort_array.cpp)
```cpp
#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &nums)
{
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
    {
        mp[nums[i]] = i;
    }
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i=0;i<nums.size();i++)
    {
        while(mp[nums[i]]!=i)
        {
            ans++;
            swap(nums[i],nums[mp[nums[i]]]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<minSwaps(v)<<endl;
    return 0;
}
```