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
        vector<int>a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        int res=INT_MIN;
        for(int i=0;i<n;i+=2)
        {
            int tmp=a[i+1]-a[i];
            res=max(res, tmp);
        }
        cout<<res<<endl;
    }
    return 0;
}