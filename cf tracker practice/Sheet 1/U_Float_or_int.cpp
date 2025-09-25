#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int ind=-1;
    string d1,d2;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='.')
        {
            ind=i;
            break;
        }
        d1+=s[i];
    }
    for(int i=ind+1;i<s.size();i++) d2+=s[i];
    if(stoi(d2)==0) cout<<"int "<<stoi(d1)<<endl;
    else cout<<"float "<<stoi(d1)<<" "<<"0."<<stoi(d2)<<endl;
    return 0;
}