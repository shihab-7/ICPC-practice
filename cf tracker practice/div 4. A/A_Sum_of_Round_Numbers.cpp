#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int cnt = 0, tmp, n, l=1;
        cin>>n;
        tmp = n;
        while(tmp)
        {
            if(tmp%10) 
            cnt++;
            tmp/=10;
        }
        cout<<cnt<<endl;
        while(n)
        {
            if(n%10)
            cout<<(n%10)*l<<" ";
            n/=10;
            l*=10;
        }
        cout<<endl;
    }
    return 0;
}

// #include <iostream>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int c = 1, a, m, b = 0;
//         cin >> a;

//         m = a;
//         while (m)
//         {
//             if (m % 10 != 0)
//                 b++;
//             m /= 10;
//         }
//         cout << b << endl;
//         while (a)
//         {
//             if (a % 10 != 0)
//                 cout << (a % 10) * c << endl;
//             a /= 10;
//             c *= 10;
//         }
//     }
// }