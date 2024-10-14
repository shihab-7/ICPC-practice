#include <bits/stdc++.h>
using namespace std;
const int N=1e7+10;
vector<bool>isPrime(N,1);

int main()
{
    isPrime[0]=false;
    isPrime[1]=false;

    for(int i=2;i<N;i++)
    {
        if(isPrime[i]==true)
        {
            for(int j = 2*i;j<N;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    int cnt=0;
    // for(auto i:isPrime) cout<<i<<" "<<cnt++<<endl;
    cout<<isPrime[3]<<endl;

    return 0;
}