#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,p;
        cin>>n>>k>>p;

        if(k==0) cout<<0<<endl;
        else if(abs(k)>n*p) cout<<-1<<endl;
        else cout<<(abs(k)+p-1)/p<<endl;
    }
    return 0;
}