/*input
8 7
1 2
2 3
4 6
5 7
3 7
6 8
1 3
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<vector<int> >  g;
vector<vector<int> > conn;
int con;

void dfs(int i)
{
    vis[i]=1;

   // cout << i << " ";
 	conn[con].push_back(i);
 	for(auto it=g[i].begin();it!=g[i].end();it++)
 	{
 		if(!vis[*it])
 			dfs(*it);
 	}
}

int main()
{
    
	int n,m,a,b,c=0;
	cin>>n>>m;
	g.clear();
	g.resize(n+1);
	conn.clear();
	conn.resize(n+1);
	con=0;
	vector<pair<int,int> > v;
	set<int> s;
	map<int,int> mp;

	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	for (int i = 1; i <g.size(); ++i)
	{
		cout<<i<<" ";
		for (int j= 0; j < g[i].size(); ++j)
		{
			mp[g[i][j]]++;
			c++;	
			cout<<g[i][j]<<" ";
			
		}
		cout<<"\n";
	}

	vis.clear();
	vis.resize(n+1);
	for (int i = 0; i <=n; ++i)
	{
		vis[i]=0;
	}
	for (int i = 1; i <= n; ++i)
	{
		if(vis[i]==0)
		{	
			dfs(i);
			con++;
		}
		
	}
cout<<"conn\n";
for (int i = 0; i <con; ++i)
	{
		cout<<i<<"\n";
		for (int j= 0; j < conn[i].size(); ++j)
		{
			cout<<conn[i][j]<<" ";			
		}
		cout<<"\n";
	}
cout<<"\n";

	for (int i = 1; i <= n; ++i)
	{	
		cout<<mp[i]<<" ";
		
		v.push_back(make_pair(mp[i],i));
		//s.insert(mp[i]);
	}
	sort(v.begin(), v.end());
	cout<<"c="<<c;
	cout<<"\n";
	
	for (int i = 0; i < 2; ++i)
	{
		cout<<v[i].first<<" "<<v[i].second<<" \n";
		c-=v[i].first;
	}
	cout<<"\n";
	cout<<c;
	return 0;
}