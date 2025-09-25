#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans = 0;
        cin>>n;
        string s;
        cin>>s;
        int a[26] = {0};
        for(int i =0 ;i<n;i++)
        {
            if(a[s[i]-'A']==0)
                ans++;
            a[s[i]-'A']++;
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
