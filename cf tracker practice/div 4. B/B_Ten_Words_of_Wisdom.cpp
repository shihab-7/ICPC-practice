#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, a=0,b=0,i=1;
        cin>>n;
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            if(x<=10 && y > b)
            {
                a = i;
                b = y; 
            }
            i++;
        }
        cout<<a<<endl;
    }
    return 0;
}