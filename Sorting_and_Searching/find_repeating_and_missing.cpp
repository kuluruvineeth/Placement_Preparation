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