#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        double angleClock(int hour, int minutes){
            float hAngle, mAngle;
            float diff;

            hour = hour % 12;
            minutes = minutes % 60;

            mAngle = minutes*6.0f;
            hAngle = hour*30.0f + minutes/2.0f;

            diff = abs(mAngle-hAngle);
            diff = min(360.0f-diff,diff);

            return diff;
        }
};

int main(){
    Solution s;
    cout<<"The Angle between them is : "<<s.angleClock(12,30)<<endl;
    return 0;
}