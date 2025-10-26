
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
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
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

ll sum_range(ll start, ll end)
{
    if(start>end) return 0;
    return (end*(end+1)/2)-((start-1)*start/2);
}
int floor_log2(int x)
{
    if(x<=0)return 0;
    return (int)floor(log2(x));
}

int main()
{
    shihab
    int n,k;
    cin>>n>>k;

    vector<int> A(n + 1);
    for(int i=1; i<=n; ++i)cin>>A[i];
    
    vector<ll> S(k+1,0);
    vector<vector<int>> L_gt(n+1,vector<int>(k+1,0));
    vector<vector<int>> R_gt(n+1,vector<int>(k+1, n+1));

    for(int i=1; i<=n; ++i)
    {
        int count=0;
        for(int j=i-1; j>=1; --j)
        {
            if(A[j]>A[i])
            {
                count++;
                if(count<=k)L_gt[i][count]=j;
                else break;
            }
        }
    }
    for(int i=1; i<=n; ++i)
    {
        int count=0;
        for(int j=i+1; j<=n; ++j)
        {
            if(A[j]>A[i])
            {
                count++;
                if(count<=k)R_gt[i][count]=j;
                else break;
            }
        }
    }
    for(int j=1; j<=k; ++j)
    {
        for(int i=1; i<=n; ++i)
        {
            if(A[i]==0)continue;
            ll B_i=floor_log2(A[i]);
            if(B_i==0)continue;
            for(int a=0; a<=j-1; ++a)
            {
                int b=j-1-a;
                int L_a;
                if(a==0)L_a=i;
                else if(a<=k && L_gt[i][a]!=0)L_a=L_gt[i][a];
                else continue;

                int L_a_plus_1;
                if(a+1<=k && L_gt[i][a+1]!=0)L_a_plus_1=L_gt[i][a+1];
                else L_a_plus_1=0;
                int R_b;
                if(b==0)R_b=i;
                else if (b <= k && R_gt[i][b] != n + 1)R_b = R_gt[i][b];
                else continue;

                int R_b_plus_1;
                if(b+1<=k && R_gt[i][b+1]!=n+1)R_b_plus_1=R_gt[i][b+1];
                else R_b_plus_1=n+1;
                ll L_start=L_a_plus_1+1;
                ll L_end=L_a;
                ll R_start=R_b;
                ll R_end=R_b_plus_1-1;
                ll N_L=L_end-L_start+1;
                ll N_R=R_end-R_start+1;
                if(N_L<=0 || N_R<=0)continue;
                ll Sum_L=sum_range(L_start, L_end);
                ll Sum_R=sum_range(R_start, R_end);
                ll Total_Len_Sum=N_L*Sum_R+N_R*(N_L-Sum_L);
                S[j]+=B_i*Total_Len_Sum;
            }
        }
    }
    for(int i=1; i<=k; ++i)cout<<S[i]<<(i==k ? "" : " ");
    cout << endl;
    return 0;
}