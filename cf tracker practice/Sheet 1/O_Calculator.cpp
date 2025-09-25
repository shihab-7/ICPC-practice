#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s,d1,d2;
    cin>>s;
    int indx=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/') 
        {
            indx=i;
            break;
        }
        d1+=s[i];
    }
    for(int i=indx+1;i<s.size();i++) d2+=s[i];
    if(s[indx]=='+') cout<<stoi(d1)+stoi(d2)<<endl;
    else if(s[indx]=='-') cout<<stoi(d1)-stoi(d2)<<endl;
    else if(s[indx]=='*') cout<<stoi(d1)*stoi(d2)<<endl;
    else if(s[indx]=='/') cout<<stoi(d1)/stoi(d2)<<endl;
    return 0;
}