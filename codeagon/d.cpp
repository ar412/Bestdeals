/*input
5
1 2 3 4 5
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
vector<pair<ll,int> > a;	

 int main()
 {
 	ios_base::sync_with_stdio(0);
 	int n;
 	cin>>n;
 	a.clear();
 	a.resize(n);
 	vector<bool> vis(n);
 	vector<ll> v;
 	vector<ll> vi;
 	vector<vector<ll> > vec(n+1);
 	for (int i = 0; i < n; ++i)
 	{
 		cin>>a[i].first;
 		a[i].second=i;
 		vis[i]=0;	
 	}
 	sort(a.begin(), a.end());
int j=0;
 	for (int i = 0; i < n; ++i)
 	{
 		if(vis[i]==0)
 		{
 			j++;
 			int r=i,c=0;
 			
 			v.clear();
 			vi.clear();
 			while(r!=a[i].second)
 			{
 				vis[i]=1;
 				v.push_back(a[i].second+1);
 				c++;
 				i=a[i].second;
 					
 			}
 			vis[i]=1;
 			v.push_back(a[i].second+1);
 			c++;
 				
 			vec.at(j).push_back(c);
 			
 			for (int i = 0; i < c; ++i)
 			{ 				
 				vec.at(j).push_back(v[i]);
 			}	
 			i=r;
 		}
 	}
 	
 			cout<<j<<" ";
 	
	for ( int i = 0; i <= j; ++i)
	{
		for (int k = 0; k < vec[i].size(); ++k)
		{
			cout<<vec[i][k]<<" ";
		}
		cout<<endl;
	}

 	return 0;
 }	
