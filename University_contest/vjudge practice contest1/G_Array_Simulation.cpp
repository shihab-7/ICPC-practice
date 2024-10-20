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
#define nl '\n'
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
        int n,o;
        cin >> n>>o;
        iv v(n);
        loop(0,n) cin>>v[i];
        while(o--)
        {
            char c;
            cin >> c;
            if(c=='S')
            {
                int d;
                cin >> d;
                for(int i=0;i<v.size();++i)
                {
                    v[i]+=d;
                }
            }
            if(c=='M')
            {
                int d;
                cin >> d;
                for(int i=0;i<v.size();++i)
                {
                    v[i]*=d;
                }
            }
            if(c=='D')
            {
                int k;
                cin>>k;
                for(int i=0;i<v.size();++i)
                {
                    v[i]/=k;
                }

            }
            if(c=='P')
            {
                int y,z;
                cin>>y>>z;
                if((y >= 0 && z < v.size())||(y < v.size() && z >= 0))
                swap(v[y],v[z]);
            }
            if(c=='R')
            {
                reverse(bgen(v));
            }
        }
        cout<<"Case "<<i<<":"<<nl;
        for(int j=0;j<v.size();++j)
        {
            cout<<v[j];
            if(j<v.size()-1) 
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}