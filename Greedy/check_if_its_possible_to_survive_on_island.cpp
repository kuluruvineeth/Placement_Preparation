#include<bits/stdc++.h>
using namespace std;
/*
N – Maximum unit of food you can buy each day.
S – Number of days you are required to survive.
M – Unit of food required each day to survive.
*/
int main()
{
    int S,N,M;
    cin>>S>>N>>M;

    int x = S/7; // to get sundays count
    int y = S - x; //to get number of days we can buy food
    int SM = S*M; //total food units required to survive S days
    int days = SM/N; //actual days required to buy required food
    if(SM%N != 0) days++;
    if(days<=y) cout<<"Yes "<<days;
    else cout<<"No";
    return 0;
}