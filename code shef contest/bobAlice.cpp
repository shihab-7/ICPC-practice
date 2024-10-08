#include<bits/stdc++.h>
using namespace std;
bool check(int n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0 ) return false;
    else return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2==1 || !check(n)) cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}