/*input
5
1 5
1 9
1 6
3
2 1
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

 int main()
 {
 	ios_base::sync_with_stdio(0); 
 	ll n,q,b;
 	ll a,m1,m2,m3,m,index;
 	priority_queue<pair<int,ll> > p;
 	set<ll> s;
 	map<ll,ll> ma;

 	ll max=0,min=INT_MAX;
 	cin>>n;
 	for (ll i = 0; i < n; ++i)
 	{
 		cin>>b;

 		if(b==1)
 		{
 			cin>>a;
 			s.insert(a);
 			ma[a]++;
 			if(a>max)
 				max=a;
 		}
 		else if(b==2)
 		{
 			cin>>a;

 			if(s.find(a)!=s.end())
 			{
 			if(ma[a]==1)
 				s.erase(a);
 			ma[a]--;

 			if(s.empty())
 				max=-1;
 			else if(a==max)
 			{
 				for (auto it:s)
 				{
 					index=it;
 				}

 			max=index;
 			}
 			}
 			else cout<<-1<<endl;

 		}
 		else if(b==3)
 		{
 			cout<<max<<endl;
 		}
 		else {

 			if(s.empty())
 				cout<<-1<<endl;
 			else {
		 	auto it=s.begin();
		 	cout<<*it;
		 	cout<<endl;
		 	}
		 }
 		
 	}
 
 	return 0;
 }
 

  /*		p.push(make_pair(ma[a],a));
 		cout<<p.top().second<<" "<<p.top().first<<endl;
*/