#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int x,y,ans;
        cin>>x;
        bool flag = false;
        for(int i=1;i<=10 && x-i>=1;i++)
        {
            y=x-i;
            ans=x^y;
            if((x+y>ans)&&(x+ans>y)&&(ans+y>x))
            {
                flag = true;
                break;
            }
        }
        if(flag) cout<<y<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}