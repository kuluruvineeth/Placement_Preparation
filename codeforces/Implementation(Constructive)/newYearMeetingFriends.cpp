#include<bits/stdc++.h>
using namespace std;

int meetingPosition[3];
int main()
{
    cin>>meetingPosition[0]>>meetingPosition[1]>>meetingPosition[2];
    sort(meetingPosition,meetingPosition+3);
    cout<<meetingPosition[2]-meetingPosition[0]<<"\n";
    return 0;
}