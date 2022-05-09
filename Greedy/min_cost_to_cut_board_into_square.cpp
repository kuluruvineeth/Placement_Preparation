/*
initially board is altogether, but after each cut it will be divided and furthur cuts will be made on the basis of different grouped sections
	eg.
	- - - -
	- - - -
	- - - -
	- - - -
	after cut in row sections will be like
	- - - -
	- - - -
	- - - -
	- - - -
	after cut in column sections will be like
	- - -   -
	- - -   -
	- - -   -
	- - -   -
	and hence cost will be accordingly
*/
#include<bits/stdc++.h>
using namespace std;

//method returns minimum cost to break board into m*n squares
int minimumCostOfBreaking(int X[],int Y[],int m,int n)
{
    int res=0;
    //sort the horizontal cost in reverse order
    sort(X,X+m,greater<int>());
    //sort the vertical cost in reverse order
    sort(Y,Y+n,greater<int>());
    //initialize current width as 1
    int hor=1,ver=1;

    //loop until one or both cost array are processed
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(X[i]>Y[j])
        {
            res += X[i]*ver;
            //increse current horizontal part count by 1
            hor++;
            i++;
        }
        else
        {
            res += Y[j]*hor;
            //increase current vertical part count by 1
            ver++;
            j++;
        }
    }
    //loop for horizontal array,if remains
    int total=0;
    while(i<m)
    {
        total += X[i++];
    }
    res += total*ver;

    //loop for vertical array, if remains
    total =0;
    while(j<n)
    {
        total += Y[j++];
    }
    res += total*hor;
    return res;
}

int main()
{
    int m=6,n=4;
    int X[m-1] = {2,1,3,1,4};
    int Y[n-1] = {4,1,2};
    cout<<minimumCostOfBreaking(X,Y,m-1,n-1);
    return 0;
}