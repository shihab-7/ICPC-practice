#include<iostream>
#include<cstdlib>
using namespace std;
int t,n,m,k,a[200005],c[105];
int main()
{
	cin >> t ;
	while(t--)
	{
		cin >> n ;int i,m=0;
		for(i=1;i<=n;i++)
		   cin >> a[i] ;
		for(i=2;i<n;i++)
		{
			m=min(a[i-1],min(a[i]/2,a[i+1]));
			a[i-1]-=m;a[i]-=2*m;a[i+1]-=m;
		}
		for(i=1;i<=n;i++)
		if(a[i]!=0) 
		{cout << "NO" << endl ;break;}
		if(i>n) cout << "YES" << endl ;
	}
} 