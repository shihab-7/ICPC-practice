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

const int N=1e6+10;
// const int N=100;
vector<bool>isPrime(N,1);

int reverse(int num)
{
    int ans=0;
    while(num!=0)
    {
        int tmp = num%10;
        ans*=10;
        ans += tmp ; 
        num/=10;
    }
    return ans;
}


int main()
{
    isPrime[0]=0;
    isPrime[1]=0;
    for(int i=2;i<N;++i)
    {
        if(isPrime[i])
        {
            for(int j=2*i;j<N;j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
    // printv(isPrime);
    shihab
    int n;
    while(cin>>n)
    {
        if(isPrime[n])
        {
            if(isPrime[reverse(n)] && n!= reverse(n))
            cout<<n<<" is emirp."<<endl;
            else cout<<n<<" is prime."<<endl;
        }
        else cout<<n<<" is not prime."<<endl;
    }
    return 0;
}