#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a;
    cin>>a;
    if(a>=0 && a<=25) cout<<"Interval [0,25]"<<endl;
    else if(a>25 && a<=50) cout<<"Interval (25,50]"<<endl;
    else if(a>50 && a<=75) cout<<"Interval (50,75]"<<endl;
    else if(a>75 && a<=100) cout<<"Interval (75,100]"<<endl;
    else cout<<"Out of Intervals"<<endl;
    return 0;
}