#include<bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin>>t; while(t--)
#define endl '\n'
#define printv(v) for(auto a:v) cout<<a<<" ";
#define printmp(m) for(auto a:m) cout<<a.first<<" "<<a.second<<endl;
#define ll long long

// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
//
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀
int main()
{
    shihab
    test
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> diff(n+1,0);
        int cur = 0;
        ll t_op = 0;
        bool impossible = false;
        for(int i=0;i<n;i++)
        {
            cur ^= diff[i];
            bool sad;
            if(cur % 2 == 0) sad = (s[i] == 'S');
            else sad = (s[i] == 'H');
            if(sad)
            {
                if(i+k > n)
                {
                    cout << -1 << endl;
                    impossible = true;
                    break;
                }
                t_op++;
                cur ^= 1;
                diff[i+k] ^= 1;
            }
        }
        if(!impossible) cout << t_op << endl;
    }
    return 0;
}