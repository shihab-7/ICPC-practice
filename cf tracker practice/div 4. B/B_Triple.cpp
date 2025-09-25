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
        map<int,int>m;
        int ans=0;
        bool flag = false;
        while(n--)
        {
            int x;
            cin>>x;
            m[x]++;
            if(m[x]==3)
            {
                flag = true;
                ans = x;
            }
        }
        if(flag)cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}