#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k,x;
        cin>>k>>x;
        long long r=x;
        for(int i=0;i<k;i++)
        {
            if((r-1)%3==0 && (r-1)/3>0 && ((r-1)/3)%2==1) r=(r-1)/3;
            else r*=2;
        }
        cout<<r<<endl;
    }
    return 0;
}