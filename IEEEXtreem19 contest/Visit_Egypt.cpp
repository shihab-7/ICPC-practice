#include<bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin>>t; while(t--)
#define endl '\n'
#define printv(v) for(auto a:v) cout<<a<<" ";
#define printmp(m) for(auto a:m) cout<<a.first<<" "<<a.second<<endl;
#define ll long long

// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

const int MAX_V_PRIME=21200000;
const ll MOD=1e9+7;
const vector<int>denominations={1,2,4,20,40,80,200,400,800};
vector<int>dp(MAX_V_PRIME+1);

void precompute_dp()
{
    dp[0]=1;
    for(int i=1; i<=MAX_V_PRIME; ++i) 
    {
        ll current_ways=0;
        for(int d:denominations)
        {
            if(i>=d)current_ways=(current_ways+dp[i-d])%MOD;
        }
        dp[i]=(int)current_ways;
    }
}

int main()
{
    shihab
    precompute_dp();
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,a;
        cin>>n>>m>>a;
        int V_prime=(int)(212*n);
        ll C=dp[V_prime];
        ll dist_M=abs(C-m);
        ll dist_A=abs(C-a);
        if(dist_M < dist_A)cout<<"Mikel"<<endl;
        else if(dist_A < dist_M)cout<<"Andrew"<<endl;
        else
        {
            if(m==C&&a==C)cout<<"TIE"<<endl;
            else cout<<"NONE"<<endl;
        }
    }
    return 0;
}