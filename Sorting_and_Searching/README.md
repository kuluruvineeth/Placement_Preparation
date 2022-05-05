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