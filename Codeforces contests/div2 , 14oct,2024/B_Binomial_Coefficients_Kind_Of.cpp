#include<bits/stdc++.h>
using namespace std;

/*######################## constants ##########################*/
typedef long long int lli;
const int inf = INT_MAX;
const lli linf = LLONG_MAX;
const auto MOD = 1000000007;

/* ############ stl containers ##############*/
typedef vector<lli>llv;
typedef pair<int,int>pii;
typedef map<int,int>mp;
typedef set<int>st;
typedef vector<int>iv;

/*################# macros #################*/
#define shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(p,n) for(auto i = p; i < n ; i++)
#define test int t; cin>>t; while(t--)
#define endl '\n'
#define bgen(a) (a).begin(), (a).end()
#define f first
#define s second
#define pb push_back
#define printv(v) for(auto a:v) cout<<a<<" ";
#define printmp(m) for(auto a:m) cout<<a.f<<" "<<a.s<<endl;

const int M = 1e9+7;
const int N = 1001;
vector<vector<int>>pre_cal(N,vector<int>(N,0));
void solve()
{
    for(int n=0;n<=N;n++)
    {
        pre_cal[n][0]=1;
        pre_cal[n][n]=1;
    }
    for(int n=1;n<N;n++)
    {
        for(int k = 1;k<N;k++)
        {
            pre_cal[n][k] = (pre_cal[n][k-1] + pre_cal[n-1][k-1]) % M;
        }
    }
}


int main()
{
    shihab
    int t;
    cin >> t;
    iv n(t),k(t);
    loop(0,t) cin>>n[i];
    loop(0,t)cin>>k[i];
    solve();
    for(int i=0;i<t;i++)
    {
        cout<<pre_cal[n[i]][k[i]]<<endl;
        //unfinished....
    }
    return 0;
}