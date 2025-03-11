#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        priority_queue<int>pq;
        for(int i=0; i<n; i++)
        {
            int val;
            cin>>val;
            pq.push(val);
        }
        while(pq.size() > 1)
        {
            int last = pq.top();
            pq.pop();
            int last2nd = pq.top();
            pq.pop();
            int x = last+ last2nd-1;
            pq.push(x);
        }
        cout<<pq.top()<<endl;
    }
    return 0;
}