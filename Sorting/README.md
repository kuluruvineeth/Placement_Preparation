# List of Sorting Algorithms for Interview Preparations

## 1. [Insertion sort](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting/insertion_sort.cpp)
```cpp
/*
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
Algorithm 
To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
*/
#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int temp = a[i];
        int j=i;
        while(j > 0 && temp < a[j-1])
        {
            a[j] = a[j-1];
            j--;
        }
        a[j]=temp;
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
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
```

## 2. [Selection sort](https://github.com/kuluruvineeth/Placement_Preparation/blob/main/Sorting/selection_sort.cpp)
```cpp
/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted. 
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray
*/
#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int mn = a[i];
        int idx=i;
        for(int j=i;j<n;j++)
        {
            if(a[j]<mn)
            {
                mn=a[j];
                idx=j;
            }
        }
        int temp;
        temp = a[i];
        a[i] = a[idx];
        a[idx] = temp;
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
    selection_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
```