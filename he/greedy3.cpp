/*input
1
4 6
1 2 10
1 3 20
1 4 30
2 3 40
2 4 50
3 4 60
*/
#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
 
int n;

int mindist(vector<int> dist,vector<bool> vset)
{
	int min=INT_MAX,index=-1;
	for (int i = 0; i <=n; ++i)
	{
		if(!vset[i] && dist[i]<=min)
			index=i,min=dist[i];
	}	

	return index;
}

int findsol(vector<int> dist)
{
	int c=0;
	for (int i = 1; i <= n; ++i)
	{
		c+=dist[i];
	}
	return c;
}

int jikstra(vector<vector<pair<int,int> > >  g,int src)
{
	vector<int> dist(n+1);
	set<pair<int,int> > s;

	for (int i = 0; i <=n; ++i)
	{
		dist[i]=INT_MIN;
	}
	dist[src]=0;
	s.insert(make_pair(0,src));	

	while(!s.empty())
	{
		pair<int,int> tmp=*(s.begin());
		int u=tmp.second;
		s.erase(s.begin());

		for (auto v = g[u].begin(); v != g[u].end(); ++v)
		{
			int weight=(*v).second;
			int e=(*v).first;
			//<<" ";
			
			cout<<weight;
			if(dist[e] < dist[u] + weight)
			{
				if(dist[e]!=INT_MAX)
					s.erase(s.find(make_pair(dist[e],e)));

				dist[e] = dist[u] + weight;
				s.insert(make_pair(dist[e],e));	
				cout<<(*s.begin()).first<<" "<<(*s.begin()).second<<"\n";
			}
		}
	}

	//cout<<dist[n]<<endl;
	return findsol(dist);
}



int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
	int m,a,b,c;
	cin>>n>>m;
	vector<vector<pair<int,int>> > g(n+1);
	vector<int> v;
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b>>c;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	int max=-1;
	for (int i = 1; i <g.size(); ++i)
	{
		int z=jikstra(g,i);
		if(z>max)
			max=z;
	}
	cout<<max;
}
    return 0;
}


//1000%107 0 

