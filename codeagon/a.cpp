/*input
1
4
1 2 4 3
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,f=0,ff=1;
		cin>>n;
		vector<ll> a(n),v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		map<ll,int> m;
		for (int i = 0; i < n; ++i)
		{
			if(m[a[i]]>0)
				f=1;
			else m[a[i]]++;

			if(1<=a[i] && a[i]<=n)
			{;}
			else f=1;
		}
		v=a;
		
		sort(v.begin(), v.end());

		for (int i = 0; i < n; ++i)
		{
			if(a[i]!=v[i])
			{
				ff=0;
				break;
			}
		}

		if(f==0 && ff==0)
			cout<<"Beautiful\n";
		else cout<<"Ugly\n";

	}



   return 0;
}  