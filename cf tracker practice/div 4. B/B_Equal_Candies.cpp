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
        int total = 0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            total+=a[i];
        }
        sort(a.begin(),a.end());
        int need= a[0]*n;
        int eat = total - need;
        cout<<eat<<endl;
    }
    return 0;
}