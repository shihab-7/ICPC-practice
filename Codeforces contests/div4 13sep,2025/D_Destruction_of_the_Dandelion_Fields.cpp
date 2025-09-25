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
        long long int s=0;
        int oc=0;
        long long minod=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            long long int v;
            cin>>v;
            s+=v;
            if(v%2==1)
            {
                oc++;
                if(v<minod) minod=v;
            }
        }
        if(oc==0) cout<<0<<endl;
        else if(oc%2==1) cout<<s<<endl;
        else cout<<s-minod<<endl;
    }
    return 0;
}