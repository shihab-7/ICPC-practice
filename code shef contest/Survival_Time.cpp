#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,d;
        cin>>n>>x>>d;
        if(n< (x*5)) cout<<d<<endl;
        else{
            int need = x*5;
            int rem = n/need ;
            int res = rem+d;
            cout<<res<<endl;
        }
    }
    return 0;
}