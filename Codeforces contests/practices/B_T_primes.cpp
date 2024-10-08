#include<bits/stdc++.h>
using namespace std;

bool checkPrime(long long int n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 ==0 || n % 3 ==0) return false;
    for(long long int i=5; i*i<= n; i+=6)
    {
        if(n % i == 0 || n % (i+2)==0) return false;
    }
    return true;
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int res = sqrt(n);
        if(res*res == n){
            if(checkPrime(res)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }    
        else cout<<"NO"<<endl;
    }
    return 0;
}