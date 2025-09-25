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
        int n,m;
        cin>>n>>m;
        string x,y;
        cin>>x>>y;
        bool flag = false;
        set<char>x1,y1;
        for(auto c:x) x1.insert(c);
        for(auto c:y) y1.insert(c);
        for(char i='a';i<='z';++i)
        {
            if(x1.find(i)==x1.end() && y1.find(i)==y1.end())
            {
                flag = true;
                break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}