/*input
2
1
20
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

map<ll, ll> F;
ll f(ll n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % mod;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % mod;
	}
}

int main()
 {
    ios_base::sync_with_stdio(0);
    int k;
    cin>>k;
  if(k==1){  
  	int t;
	cin>>t;
	ll a,b,c;	

	while(t--)
	{
		ll n;
		cin>>n;
		//n=n%mod;
		//cout<<n<<endl;
		a=1;
		b=2;
		for (int i = 2; i <=n; ++i)
		{
			c = (a+b)%mod;
			a=b;
			b=c;
		}

		cout<<b<<endl;
	}
}
else if(k==2){

	int t;
	cin>>t;
	long long int f[100000];
	f[1]=2;
	f[2]=3;
	for (int i = 3; i <=100000; ++i)
	{
		f[i] = ((f[i-1])+(f[i-2]))%mod;
	}
	while(t--)
	{
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
}
else {
	

int t;
	cin>>t;
		ll n;
		

	F[1]=1;F[0]=1;
	while (t--)
	{
	cin>>n;
	cout << (n==0 ? 0 : f(n-1)) << endl;
	//cout<<f(n-1)<<" "<<f(n)<<" "<<f(n+1)<<" \n";
	}

}

    return 0;
 }