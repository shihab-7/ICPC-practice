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
        int Ox,Oy,Ax,Ay,Bx,By;
        cin>>Ox>>Oy>>Ax>>Ay>>Bx>>By;
        int x1 = Ax-Ox,y1=Oy-Ay, x2=Bx-Ox,y2=By-Oy, x3=Ax-Bx,y3=Ay-By;
        double a = sqrt((x1*x1)+(y1*y1));
        double b = sqrt((x2*x2)+(y2*y2));
        double c = sqrt((x3*x3)+(y3*y3));
        double ang = acos(((a*a)+(b*b)-(c*c))/(2*a*b));
        double ans = b*ang;
        cout<<fixed<<setprecision(8)<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}