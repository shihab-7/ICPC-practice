#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char x;
        cin>>x;
        string s="codeforces";
        if(s.find(x)==-1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}