#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long f,s,t,fo;
    f=a%100;
    s= (f*(b%100))%100;
    t=(s*(c%100))%100;
    fo=(t*(d%100))%100;
    
    cout<<(fo%100)/10<<fo%10<<endl;
    return 0;
}