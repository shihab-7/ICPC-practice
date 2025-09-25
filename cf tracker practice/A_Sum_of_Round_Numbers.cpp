#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int cnt = 0, tmp, n, l=1;
        cin>>n;
        tmp = n;
        while(tmp)
        {
            if(tmp%10) 
            cnt++;
            tmp/=10;
        }
        cout<<cnt<<endl;
        while(n)
        {
            if(n%10)
            cout<<(n%10)*l<<" ";
            n/=10;
            l*=10;
        }
        cout<<endl;
    }
    return 0;
}
