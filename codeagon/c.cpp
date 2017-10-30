/*input
11 4 3
0 0 0 1 0 1 0 1 1 1 0
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

 int main()
 {
 	ios_base::sync_with_stdio(0); 
 
 	ll n,m,k,c=0,t=0;
 	cin>>n>>m>>k;
 	vector<ll> a(n),b;
 	set<ll> z;
 	for (ll i = 0; i < n; ++i)
 	{
 		cin>>a[i];
 	}
 
 	for (ll i = 1; i < n; ++i)
 	{		
 		//cout<<i<<" "<<t<<"\n";

 		if(a[i]==1)
 			c++,b.push_back(i);
 			
 	}
 	if(c<m)
 		cout<<-1;
 	else 
 	{
 		for (ll j = 0; j <= b.size()-m; ++j)
 		{
 			c=1;
 			t=b[j];
 			//cout<<t<<" ";
 			for (ll i = j+1; i-j < m; ++i)
 		{
 			
	 		//cout<<c*k*(b[i]-b[i-1])<<" ";
	 		t+=c*k*(b[i]-b[i-1]);
	 		c++
;	 		//cout<<i<<" "<<t<<" "<<c<<"\n";
 		}
 			//cout<<i-m<<" "<<t<<"\n";
 			/*t-=(b[i-m]+k*(b[i-m+1]-b[i-m]));
 			cout<<t<<"\n";   
 			t+=(m*k*(b[i]-b[i-1])+b[i-m+1]);
 			cout<<t<<"\n";			
 			*/
 		//cout<<j<<" "<<t<<"\n";
	 		z.insert(t);
 		}
 		auto it = z.begin();
 	cout<<*it;
 	}

 	//cout<<t;
 	return 0;
 }



 