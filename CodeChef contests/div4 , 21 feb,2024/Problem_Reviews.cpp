#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        bool found = false;
        while(n--)
        {
            int i;
            cin>>i;
            if(i <= 4) found = true;
        }
        if(found) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}