#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        v[0]=v[0]+1;
        long long int res = 1;
        for(int i=0;i<n;i++)
        {
            res*=v[i];
        }
        cout<<res<<endl;
    }
    return 0;
}