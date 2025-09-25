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

bool isPrime(int n) {
    if (n <= 1) {
        return false; // Handle edge cases: 0 and 1 are not prime
    }
    if (n <= 3) {
        return true; // Handle small primes: 2 and 3 are prime
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false; // Check divisibility by 2 and 3
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false; // Check divisibility by 6k ± 1
        }
    }
    return true; // If no divisors found, n is prime
}

int main()
{
    shihab
    int n;
    cin >> n;
    int tax=1;
    if(n > 2)
    {
        
        if(isPrime(n)) 
        {
            for(int i=2;i*i<=n-1;++i)
            {
                if((n-1) % i == 0)
                {
                    tax=max(tax,i);
                }
            }
        }
        else 
        {
            for(int i=2;i*i<=n;++i)
            {
                if(n % i == 0)
                {
                    tax=max(tax,i);
                }
            }
        }
    }
    cout<<tax<<endl;
    return 0;
}