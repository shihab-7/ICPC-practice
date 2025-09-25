#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s="";
        for(int i = 0;i<8;i++)
        {
            for(int j =0;j<8;j++)
            {
                char a;
                cin>>a;
                if(a!='.')
                {
                    s += a ;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}