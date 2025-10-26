#include <bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
//
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

const int MAX_K=10000;

int main() 
{
    shihab
    int n;
    ll k;
    cin>>n>>k;
    vector<int>C_costs(n+1);
    set<int>urt;
    for(int i=0; i<n-1; ++i) 
    {
        cin>>C_costs[i];
        urt.insert(2*C_costs[i]);
    }
    vector<bool>dp(MAX_K+1,0);
    dp[0]=true;
    for(int r:urt)
    {
        if(r==0) continue;
        for(int i=r; i<=MAX_K; ++i) 
        {
            if(dp[i-r]) dp[i]=true;
        }
    }
    int q;
    cin>>q;
    while(q--) 
    {
        int a,b;
        cin>>a>>b;
        ll C_base=0;
        bool valid=true;
        if(a<0 ||a>=n ||b<0 ||b>=n) valid=false;
        
        if(a==0 && b==0)C_base = 0;
        else if(a==0 && b>0 &&b<n)C_base=C_costs[b - 1];
        else if(a>0 &&a<n && b==0)C_base=C_costs[a - 1];
        else if(a>0 && a<n &&b>0 &&b<n) C_base=C_costs[a - 1] + C_costs[b - 1];
        else valid = false;
        if(!valid || C_base>k)
        {
            cout<<"No"<<endl;
            continue;
        }
        ll k_remainder=k-C_base;
        if(k_remainder<=MAX_K && dp[k_remainder]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}