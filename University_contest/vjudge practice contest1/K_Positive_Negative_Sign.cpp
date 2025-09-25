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

int main()
{
    shihab
    int i=0;
    test
    {   
        ++i;
        int n,m;cin >> n >> m;
        int sum = 0, sign = -1;
        int gap_sum = (n*1)+(((m+1)*(n-1)*n)/2);
        int totalsum = ((1+n)*n)/2;
        sum = totalsum - gap_sum;
        // for(int j=1;j<=n;++j)
        // {
        //     sum+= (j*sign);
        //     if(j % m == 0) sign*=-1;
        // }
        cout<<"Case "<<i<<": "<<gap_sum<<endl;
    }
    return 0;
}