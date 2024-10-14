#include <bits/stdc++.h>
using namespace std;

void PrintBinary(int x)
{
    for(int i=10;i>=0;--i)
    {
        cout<<((x >> i) & 1);
    }
    cout<<endl;
}

int main()
{
    int a=4,i=1;
    // cout<<(a | (1<<i))<<endl;
    PrintBinary(a);
    PrintBinary((a | (1<<i))); //set bit at position i
    PrintBinary((a & (~(1<<i)))); // unset bit at position i
    PrintBinary(a ^ (1<<i)); // toggle bit at position i

    //set bit count korar jonno
    cout<< __builtin_popcount(a)<<endl;; // int range er jonno
    cout<< __builtin_popcountll((long long) a)<<endl; // long long range er jonno

    // tasara loop diye mnually count kora jay
    int cnt=0;
    for(int i=31;i>=0;--i)
    {
        if((a >> i) & 1) cnt++;
    }
    cout<<cnt<<endl;

    int a1 = 2,b=5;
    a1 = a1 ^ b;
    b = b ^ a1;
    a1 = a1 ^ b;
    cout<<a1<<" "<<b<<endl;
    return 0;
}