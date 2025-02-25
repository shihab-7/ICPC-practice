#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       string s;
       cin>>n;
       cin>>s;
       long long hcnt=0, ucnt=0;
       for(char c:s)
       {
        if(c=='-') hcnt++;
        else if(c=='_') ucnt++;
       }
       if(hcnt < 2 || ucnt < 1) cout<<0<<endl;
       else cout<<((hcnt/2)*((hcnt+1)/ 2))*ucnt<<endl;
    }
    return 0;
}