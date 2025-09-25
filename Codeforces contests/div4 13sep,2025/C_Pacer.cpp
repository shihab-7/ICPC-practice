#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,m;
        cin>>n>>m;
        vector<long long int>a(n+1),b(n+1);
        long long int wt=0;
        a[0]=0;
        b[0]=0;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
        for(int i=1;i<=n;i++)
        {
            long long int d=a[i]-a[i-1];
            long long int df= abs(b[i]-b[i-1]);
            if((d%2)!=(df%2)) wt++; 
        }
        cout<<m-wt<<endl;
    }
    return 0;
}