#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string x = "codeforces";
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=x[i])
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}