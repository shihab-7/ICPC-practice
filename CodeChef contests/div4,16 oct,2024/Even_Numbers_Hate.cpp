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
        cin >> n;
        iv v(n);
        loop(0,n) cin>>v[i];
        int even=0,odd=0;
        loop(0,n)
        {
            if((v[i] & 1)) odd++;
            else even++;
        }
        int assm = odd - 1;
        int rem = assm / 2;
        bool flag = false;
        loop(0,n)
        {
            if((v[i] & 1))
            {
                flag = true;
                break;
            }
        }
        (flag)?cout<<even+rem+1<<endl:cout<<0<<endl;
    }
    return 0;
}
