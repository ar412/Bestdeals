/*input
100 100 100 100
4
50 50 50 49
50 50 50 49
50 50 50 49
50 50 50 49
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<pair<pair<int,int>,pair<int,int> > >v;
int n; 	

 int main()
 {
 	ios_base::sync_with_stdio(0);
 	int a,b,c,d,a2,b2,c2,d2,f=0; 
 	cin>>a2>>b2>>c2>>d2>>n;
 	v.clear();
 	v.resize(n);

 	for (int i = 0; i < n; ++i)
 	{
 		cin>>v[i].first.first>>v[i].first.second>>v[i].second.first>>v[i].second.second;
 	}

 	for (int j = 1; j <= n; ++j)
 	{
 		for (int k = 0; k <= n-j ; ++k)
 		{	
 			a=0,b=0,c=0,d=0;
 			for (int i = k; i < k+j; ++i)
 			{
 				a+=v[i].first.first;
 				b+=v[i].first.second;
 				c+=v[i].second.first;
 				d+=v[i].second.second;
 			}
 			
 			if(a==a2 && b==b2 && c==c2 && d==d2)
 				{f=1;
 				break;}
 		}
 		if(f==1)
 			break;
 	}

 	if(f==1)
 		cout<<"YES\n";
 	else 
 		cout<<"NO\n";
 	return 0;
 }
 
