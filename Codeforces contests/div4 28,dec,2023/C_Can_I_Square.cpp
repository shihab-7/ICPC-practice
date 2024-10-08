#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        long long int n,sum=0;
        cin>>n;
        while(n--){
            long long int s;
            cin>>s;
            sum+=s;
        }
        long long int x = sqrt(sum);
        if(x*x == sum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}