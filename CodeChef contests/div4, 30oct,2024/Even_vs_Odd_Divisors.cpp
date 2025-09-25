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
        int num, ev=0,od=0;
        cin>>num;
        for(int i=1;i<=num;++i)
        {
            int ind;
            if(num % i == 0)
            {
                ind=i;
                if(ind % 2 ==0) ev++;
                else od++;
            }
        }
        if(ev>od) cout<<1<<endl;
        if(ev==od) cout<<0<<endl;
        if(ev<od) cout<<-1<<endl;
    }
    return 0;
}