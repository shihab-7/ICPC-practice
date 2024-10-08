#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--){
        string x,y,z;
        cin >> x >> y >> z ;
        string s = x+y+z;
        int c1=0,c2=0,c3=0;
        for(int i=0;i<9;i++){
            if(s[i]=='A') c1++;
            if(s[i]=='B') c2++;
            if(s[i]=='C') c3++;
        }
        if(c1==2) cout << 'A' << endl;
        if(c2==2) cout << 'B' << endl;
        if(c3==2) cout << 'C' << endl;
    }
        
    return 0;
}