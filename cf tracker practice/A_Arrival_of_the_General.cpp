#include<bits/stdc++.h>
using namespace std;
int main(){
	int mx=0,mn=150,n,x,L,R,ans;
	cin>>n;
	for(int i=0;i<=n;i++) {
		cin>>x;
		if(x>mx) mx=x,L=i;
		if(x<=mn) mn=x,R=i;
	}
	ans=(L-1)+(n-R);
	if(R<L) ans--;
	cout<<ans; 		
}	
