#include<bits/stdc++.h>
using namespace std;

void check_rotated(string a, string b)
{
    a += a;
    //now string b must be sub-string of a.
    //find will return 0th based index from where the substring will start
    if(a.find(b) != string::npos) cout<<"YES";
    else cout<<"NO";
}

int main()
{
    check_rotated("abcd","cdab");
    return 0;
}