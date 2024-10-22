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
        double r1, r2, r3;
        cin >> r1 >> r2 >> r3;

        //triangle calc
        double a=r2+r3, b=r1+r3, c=r1+r2;
        //ordho porishima
        double s = (a+b+c)/2.0;
        double t_area = sqrt(s*(s-a)*(s-b)*(s-c));

        //angles
        double angA= acos(((b*b)+(c*c)-(a*a))/(2.0*b*c));
        double angB= acos(((a*a)+(b*b)-(c*c))/(2.0*a*b));
        double angC= acos(((a*a)+(c*c)-(b*b))/(2.0*a*c));
        //trivuj er faka onshor area
        double A1 = 0.5*r1*r1*angA;
        double B1 = 0.5*r3*r3*angB;
        double C1 = 0.5*r2*r2*angC;
        double total_free_space = A1+B1+C1 ;

        // blue area
        double ans = t_area - total_free_space;
        cout<<fixed<<setprecision(10)<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}