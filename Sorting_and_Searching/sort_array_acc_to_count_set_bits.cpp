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