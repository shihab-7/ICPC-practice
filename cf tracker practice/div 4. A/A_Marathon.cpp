#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    vector<int>v;
    while(t--)
    {
        v.clear();
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        v.push_back(b);
        v.push_back(c);
        v.push_back(d);
        int cnt =0;
        for(int i=0;i<3;i++)
        {
            if(v[i]>a) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}