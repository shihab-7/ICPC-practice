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
        for(int i=0;i<n;i++) cin>>a[i];
        int cnt0=0, cnt_1=0,res;
        for(int val:a)
        {
            if(val==0) cnt0++;
            if(val==-1) cnt_1++;
        }
        if(cnt_1%2==1) res=cnt0+2;
        else res=cnt0;
        cout<<res<<endl;
    }
    return 0;
}