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
        string s;
        cin>>n;
        cin>>s;
        int cnta=0,cntb=0;
        for(char v:s)
        {
            if(v=='a') cnta++;
            else if(v=='b') cntb++;
        }
        if(cnta==1 || cntb==1) cout<<1<<endl;
        else if(cnta>1 && cntb>1 && cnta==cntb) cout<<s.length()<<endl;
        else if(cnta > cntb) cout<<s.length()-(cnta-cntb)<<endl;
        else if (cnta < cntb) cout<<s.length()-(cnta-cntb)<<endl;
    }
    return 0;
}