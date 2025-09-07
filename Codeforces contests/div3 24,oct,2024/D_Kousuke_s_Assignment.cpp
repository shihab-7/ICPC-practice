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
        int n;
        cin>>n;
        iv v(n);
        loop(0,n)cin>>v[i];
        lli curr_sum=0;
        int seg_cnt=0;
        unordered_set<int>track;
        loop(0,n)
        {
            curr_sum+=v[i];
            if(curr_sum==0 || track.count(curr_sum))
            {
                seg_cnt++;
                curr_sum=0;
                track.clear();
            }
            track.insert(curr_sum);
        }
        cout<<seg_cnt<<endl;
    }
    return 0;
}