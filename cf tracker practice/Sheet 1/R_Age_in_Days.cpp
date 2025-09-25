#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long d;
    cin>>d;
    cout<<d/365<<" years"<<endl<<(d%365)/30<<" months"<<endl<<(d%365)%30<<" days"<<endl;
    return 0;
}