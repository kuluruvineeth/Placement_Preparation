#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s)
{
    int len = s.size();
    for(int i=0;i<len/2;i++)
    {
        if(s[i]!=s[len-i-1]) return 0;
    }
    return 1;
}

int main()
{
    string s = "abba";
    if(isPalindrome(s)) cout<<"string is palindrome"<<endl;
    else cout<<"string is not plaindrome"<<endl;
    return 0;
}