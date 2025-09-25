#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        string s;
        long long int a=1e9,b=1e9,c=1e9,d;
        while(n--)
        {
            cin>>d>>s;
            if(s=="11") a=min(a,d);
            if(s=="10") b= min(b,d);
            if(s=="01") c= min(c,d);
        }
        if(a!=1e9 || min(a,b+c)!=1e9) cout<<min(a,b+c)<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}