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
        int res = 0 , cnt = 0;
        while(n--)
        {
            int a;
            cin>>a;
            if(a) cnt = 0;
            else cnt++;
            res = max(res,cnt);
        } 
        cout<<res<<endl;
    }
    return 0;
}