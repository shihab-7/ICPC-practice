#include<bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin>>t; while(t--)
#define endl '\n'
#define printv(v) for(auto a:v) cout<<a<<" ";
#define printmp(m) for(auto a:m) cout<<a.first<<" "<<a.second<<endl;
#define ll long long
const ll MOD = 1e9+7;
// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
//
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

int main()
{
    shihab
    int n;
    cin>>n;
    vector<ll> a(n+1,0),b(n+1,0),dp(n+1,0);
    a[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;;j++)
        {
            int v1=j*(3*j-1)/2;
            int v2=j*(3*j+1)/2;

            ll sign=(j%2==1)?1:-1;
            if(i-v1>=0) a[i]=(a[i]+sign*a[i-v1]+MOD)% MOD;
            else break;
            if(i-v2>=0) a[i]=(a[i]+sign*a[i-v2]+MOD)% MOD;
        }
    }
    b[0]=0,b[1]=0;
    for(int i=2;i<=n;i++) b[i]=(b[i-1]+a[i-2])% MOD;

    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=(dp[i-1]+b[i])% MOD;
    for(int i=1;i<=n;i++) cout<<dp[i]<<(i==n?"":" ");
    cout<<endl;
    return 0;
}