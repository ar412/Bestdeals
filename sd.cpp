/*input

*/
#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
 
vector<bool> vis;
vector<vector<int> > g;

int dfs(vector<bool> v,int n)
{

	//vis[src]=1;
	vector<int> dis(n+1);
	for (int i = 0; i <=n; ++i)
	{
		dis[i]=INT_MAX;
	}
	dis[1]=0;

	stack<int> s;
	s.push(1);
	int c=0;

	while(!s.empty())
	{
		int x=s.top();
		s.pop();
		//c+=g[x].size();
	
	for (int i = 0; i < g[x].size(); ++i)
	{
		int d=g[x][i];
		if(dis[d] > dis[x]+1)
		{
			dis[d] = dis[x]+1;
			
			s.push(d);
			if(v[d]==1)
				return d;
		}

	}
	}
return 0;
}

void  bfs(int src)
{
	vis[src]=1;
	queue<int> q;
	q.push(src);

	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		vis[s]=1;

	for (int i = 0; i <	g[s].size() ; ++i)
	{
		int d=g[s][i];
		if(!vis[d])
		{
			q.push(d);
		}
	}

	}

	
}




int main()
{
	int n,m,a,b,x,max=INT_MIN,c;
	cin>>n>>m;
	vector<int> v(n+1);
	g.clear();
	g.resize(n+1);

	for (int i = 0; i <=n; ++i)
	{
		vis.push_back(0);
		v[i]=0;
	}
	c=0;
	
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		g[a].push_back(b);
		v[b]++;
	}
	for (int i = 0; i <=n; ++i)
	{
		if(v[i]==0)
			//v[i]++;{}
		{}
	}
	for (int i = 1; i <=n; ++i)
	{
		if(g[i].size() > v[i])
			cout<<i<<" "<<g[i].size()<<" "<<v[i]<<" \n",
			c++;
	}
cout<<c<<endl;
	
	for (int i = 1; i <=n; ++i)
	{
		if(!vis[i])
		{
			bfs(i);
			c--;
		}
	}
cout<<c<<endl;	
	/*for (int i = 1; i <=n; ++i)
	{
		cout<<i<<" ";
		for (int j = 0; j <g[i].size() ; ++j)
		{
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<v[1];
	cout<<dfs(v,n);
	vector<int> dis= bfs(n);
	pair<int,int> min;
	min=make_pair(INT_MAX,INT_MAX);
	for (int i = 2; i <=n; ++i)
	{
		if(dis[i]<min.first && v[i]==1)
			if(i<min.second)
				min=make_pair(dis[i],i);
	}

	cout<<min.second;

	*/

    return 0;
}


//1000%107 0 

