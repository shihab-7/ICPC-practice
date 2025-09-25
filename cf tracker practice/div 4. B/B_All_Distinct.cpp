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
        int x;
        set<int>s;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            s.insert(x);
        }
        cout<<s.size()-(n-s.size())%2<<endl;
    }
    return 0;
}