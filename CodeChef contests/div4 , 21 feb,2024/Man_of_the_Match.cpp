#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<pair<int,int>>n(22);
        int a,b;
        for(int i=0;i<22;i++)
        {
            cin>>a>>b;
            n[i] = make_pair(a,b);
        }
        int max_score = -1;
        int pos = -1;
        for(int i=0;i<22;i++)
        {
            int points = n[i].first + n[i].second*20;
            if (points > max_score)
            {
                max_score = points;
                pos = i;
            } 
        }
        cout<<pos+1<<endl;
    }
    return 0;
}