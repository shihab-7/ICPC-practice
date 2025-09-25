#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[n];
        for(int i =0 ;i<n;i++)
        {
            cin>>ar[i];
        }
        int mihai =0 , bianca =0;
        for(int i =0 ;i<n;i++)
        {
            if(ar[i]%2==0) mihai +=ar[i];
            else bianca += ar[i];
        }
        if(mihai > bianca) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}