#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt =0, n;
        string s;
        cin>>n>>s;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='*' && s[i+1]=='*') break;
            else if(s[i]=='@') cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}