#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    cin>>i;
    while(i--)
    {
        vector<int>v;
        int x,y,z;
        cin>>x>>y>>z;
        v.push_back(x);
        v.push_back(y);
        v.push_back(z);
        
        sort(v.begin(),v.end());
        cout<<v[1]<<endl;
    }
    return 0;
}