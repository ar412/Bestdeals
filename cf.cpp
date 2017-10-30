/*input
3
1 3 5
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll n,s=0;
	cin>>n;
	std::vector<ll> a(n),c;
	map<ll,ll> m;
	for (ll i = 0; i < n; ++i)
	{
		cin>>a[i];
		s+=a[i];
		if(m[a[i]]==0)
			c.push_back(a[i]);
			m[a[i]]++;
	}
	sort(c.begin(),c.end());
	for (int i = 0; i < c.size(); ++i)
	{
		/* code */cout<<c[i]<<" ";
	}
	cout<<"\n";
	s=s/2+1;
	std::vector<ll> v(s+1);
	for (ll i = 0; i <= s; ++i)
	{
		v[i]=1000000000;
	}
	v[0]=0;
	for (ll i = 1; i <= s; ++i)
	{
		for (ll j = 0; j < c.size(); ++j)
		{
			if(c[i]<=i && v[i-c[j]]+1<v[i])
				v[i]=v[i-c[j]]+1;
		}
	}
	for (ll i = 0; i <=s; ++i)
	{
		cout<<v[i]<<" ";
	}




	return 0;
}




