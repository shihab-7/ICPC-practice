#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        long long int x,y;
        cin>>n>>m>>x>>y;
        vector<long long int>v1(n),v2(m);
        for(int i=0;i<n;i++) cin>>v1[i];
        for(int i=0;i<m;i++) cin>>v2[i];
        cout<<n+m<<endl;
    }
    return 0;
}