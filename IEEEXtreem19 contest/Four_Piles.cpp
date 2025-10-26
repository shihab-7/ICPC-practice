#include<bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test int t;cin>>t;while(t--)
#define endl '\n'
#define printv(v) for(auto a:v)cout<<a<<" ";
#define printmp(m) for(auto a:m)cout<<a.first<<" "<<a.second<<endl;
#define ll long long

// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

const ll MOD=1e9+7;
const int MAX_BITS=60;
ll memo[MAX_BITS][2][2][2][2];
ll X[4];

ll digit_dp(int p, int t1, int t2, int t3, int t4)
{
    if(p<0)return 1;
    if(memo[p][t1][t2][t3][t4]!=-1)return memo[p][t1][t2][t3][t4];
    ll ans=0;
    int limit[4];
    limit[0]=t1 ? ((X[0]>>p)&1):1;
    limit[1]=t2 ? ((X[1]>>p)&1):1;
    limit[2]=t3 ? ((X[2]>>p)&1):1;
    limit[3]=t4 ? ((X[3]>>p)&1):1;
    for(int i=0; i<=limit[0]; ++i)
    {
        for(int j=0; j<=limit[1]; ++j)
        {
            for(int k=0; k<=limit[2]; ++k)
            {
                int b_d=i^j^k;
                if(b_d<=limit[3])
                {
                    int nt1=t1&&(i==limit[0]);
                    int nt2=t2&&(j==limit[1]);
                    int nt3=t3&&(k==limit[2]);
                    int nt4=t4&&(b_d==limit[3]);
                    ans=(ans+digit_dp(p-1, nt1, nt2, nt3, nt4))%MOD;
                }
            }
        }
    }
    return memo[p][t1][t2][t3][t4]=ans;
}

ll compute_F(ll X1, ll X2, ll X3, ll X4)
{
    if(X1<0 || X2<0 || X3<0|| X4<0)return 0;
    X[0] = X1;
    X[1] = X2;
    X[2] = X3;
    X[3] = X4;
    for(int i=0; i<MAX_BITS; ++i)
    {
        for(int j=0; j<2; ++j)
        {
            for(int k=0; k<2; ++k)
            {
                for(int l=0; l<2; ++l)
                {
                    for(int m=0; m<2; ++m)
                    {
                        memo[i][j][k][l][m]=-1;
                    }
                }
            }
        }
    }
    return digit_dp(MAX_BITS-1, 1, 1, 1, 1);
}

int main()
{
    shihab
    int q;
    cin>>q;
    while(q--)
    {
        ll A[4], B[4];
        for(int i=0; i<4; ++i)
            cin>>A[i]>>B[i];
        ll N_total=1;
        for(int i=0; i<4; ++i)
        {
            ll count=B[i]-A[i]+1;
            N_total=(N_total*count)%MOD;
        }
        ll N_lose=0;
        for(int mask=0; mask<(1<<4); ++mask)
        {
            ll Y[4];
            for(int i=0; i<4; ++i)
            {
                if((mask>>i)&1)Y[i]=A[i]-1;
                else Y[i]=B[i];
            }
            ll count_F=compute_F(Y[0], Y[1], Y[2], Y[3]);
            if(__builtin_popcount(mask)%2==1) N_lose=(N_lose-count_F+MOD)%MOD;
            else N_lose=(N_lose+count_F)%MOD;
        }
        ll N_win=(N_total-N_lose+MOD)%MOD;
        cout<<N_win<<endl;
    }
    return 0;
}
