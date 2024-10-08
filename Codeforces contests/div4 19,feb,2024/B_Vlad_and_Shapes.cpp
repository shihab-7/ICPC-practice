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

/*############# basic functions ######################*/

//custom compare function
bool comp(pii &a,pii &b)
{
    // to use in ascending order pair sort
    return a.f < b.f || (a.f == b.f && a.s < b.s);
    //to use in descending order pair sort
    //return a.f > b.f || (a.f == b.f && a.s > b.s);
}
//prime check
bool isPrime(int n)
{
    if (n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6) if(n%i==0 || n%(i+2)==0) return false;
    return true;
}
// to reverse sort function
bool rev(int &a,int &b)
{
    return a > b;
}

int main()
{
    shihab
    test{
        int n;
        cin>>n;
        bool flag = false;
        int sum=0;
        loop(0,n)
        {   sum = 0;
            loop(0,n)
            {
                char c;
                cin>>c;
                if(c=='1') sum++;
            }
            if(sum == 1) flag = true;
        }
        if(flag) cout<<"TRIANGLE"<<endl;
        else cout<<"SQUARE"<<endl;
    }
    return 0;
}