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
    test
    {
        int n,k;
        cin >> n >>k;
        
        unordered_map<int, vector<int>> b_costs;
        
        for(int i=0;i<k;++i)
        {
            int b,c;
            cin>>b>>c;
            b_costs[b].pb(c);
        }

        iv mx_cost;
        for(auto &val:b_costs)
        {
            iv &tmp_cost = val.second;
            sort(tmp_cost.rbegin(),tmp_cost.rend());
            for(int i=0;i<min(n,(int)tmp_cost.size());++i)
            {
                mx_cost.pb(tmp_cost[i]);
            }
        }
        sort(mx_cost.rbegin(),mx_cost.rend());
        lli mx_ern=0;
        for(int i=0;i<min(n,(int)mx_cost.size());++i)
        {
            mx_ern+=mx_cost[i];
        }
        cout<<mx_ern<<endl;
    }
    return 0;
}
