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
        string s;
        cin>>s;
        int q;
        cin>>q;
        set<int>pos;
        if(s.size() >=4)
        {
            for(int i=0;i<=s.size();++i)
            {
                if(s.substr(i,4)=="1100") pos.insert(i);
            }
        }
        while(q--)
        {
            int indx,val;
            cin>>indx>>val;
            indx--;
            s[indx]='0'+val;
            for(int i= max(0,indx-3);i<=min((int)s.size()-4,indx);++i)
            {
                if(i+4<=s.size()&& s.substr(i,4)=="1100")
                pos.insert(i);
                else pos.erase(i);
            }
            if(!pos.empty())
            cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}