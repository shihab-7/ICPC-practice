#include<bits/stdc++.h>
using namespace std;

bool found(vector<int>&v,int n)
{
    if(n<8) return false;
    unordered_map<int,int>track;
    for(int i=0;i<n;i++)
    {
        track[v[i]]++;
    }
    vector<int> given={0,1,0,3,2,0,2,5};
    for(int val : given)
    {
        if(track[val]==0)
        return false;
        track[val]--;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans=0;
        for(int i=8;i<=n;i++)
        {
            if(found(a,i))
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}