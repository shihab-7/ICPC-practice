#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >>n>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>> a[i];
        }
        sort(a.begin(),a.end());
        long long ans=0,tmp=0;
        for(int i=n-1;i>=0;--i)
        {
            tmp++;
            if(a[i]*tmp>=x)
            {
                ans++;
                tmp=0;
            }
        }
        cout<<ans<< endl;
    }
}