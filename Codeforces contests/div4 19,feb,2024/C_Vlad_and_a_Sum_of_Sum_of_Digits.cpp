#include <bits/stdc++.h>
#define  shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define lli long long int
using namespace std;
lli arr[2000004];
void fixed_size()
{
    for (lli i = 1; i <= 2000002; i++)
        {
           lli tmp = i;
            while (tmp)
            {
                arr[i] += tmp % 10;
                tmp /= 10;
            }
            arr[i]+=arr[i-1];
        }
}
int main()
{
    shihab
    lli t;
    cin >> t;
    fixed_size();
    while (t--)
    {
        lli n;
        cin >> n;
        cout <<arr[n]<<endl;
    }
    return 0;
}