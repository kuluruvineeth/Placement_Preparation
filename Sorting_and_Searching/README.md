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