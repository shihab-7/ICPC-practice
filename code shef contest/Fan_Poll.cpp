#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int mx=a;
    if (b > mx) mx = b;
    else if(c > mx) mx = c;
    if(mx == a) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}