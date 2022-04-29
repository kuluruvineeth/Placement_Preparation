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