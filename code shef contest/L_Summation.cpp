#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll sum(ll a[],ll i,int n)
{
    if(i==n) return 0;
    ll res = a[i]+sum(a,i+1,n);
    return res;
}
int main()
{
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans = sum(a,0,n); 

    cout<<ans;
    return 0;
}