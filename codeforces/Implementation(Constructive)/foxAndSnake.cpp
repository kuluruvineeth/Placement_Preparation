#include<bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false),cin.tie(NULL));

int main()
{
    fastread()

    int n,m;
    bool right = true,left=false;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i&1){
                cout<<"#";
            }
            else{
                if(right==true){
                    if(j==m){
                        cout<<"#";
                        right=false;
                        left=true;
                    }
                    else{
                        cout<<".";
                    }
                }
                else if(left==true){
                    if(j==1){
                        cout<<"#";
                    }
                    else{
                        cout<<".";
                        if(j==m){
                            left = false;
                            right = true;
                        }
                    }
                }
            }
        }
        cout<<"\n";
    }
    cout<<"\n";
    return 0;
}