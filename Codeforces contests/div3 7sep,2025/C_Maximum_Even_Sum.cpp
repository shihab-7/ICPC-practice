#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,res=-1;
        cin>>a>>b;
        long long s1=a+b, s2=a*b+1;
        if(s1%2==0) res=max(res,s1);
        if(s2%2==0) res=max(res,s2);
        if(b%2==0)
        {
            long long s3=2*a+b/2 ,s4=a*(b/2)+2;
            if(s3%2==0) res=max(res,s3);
            if(s4%2==0) res=max(res,s4);
        }
        cout<<res<<endl;
    }
    return 0;
}