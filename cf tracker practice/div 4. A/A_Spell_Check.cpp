#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string x= "Timur";
    sort(x.begin(),x.end());
    while(t--)
    {
        int sz;
        string s;
        cin>>sz>>s;
        sort(s.begin(),s.end());
        if(sz==5)
        {
            if(s == x) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if (sz<5) 
        cout<<"NO"<<endl;
        else if (sz>5) 
        cout<<"NO"<<endl;
    }
    return 0;
}