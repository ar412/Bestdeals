/*input
1
3 2
1 2
2 3

*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define MAX 100001
using namespace std;


int aabra(vector<vector<int> > v,int x)
{
		
		 int count=0,s,n=v.size();
		bool vis[n+1];
		int level[n+1];
		for (int i = 0; i <=n; ++i)
		{
			vis[i]=0;
			level[i]=0;	
		}
		queue<int> q;
		q.push(1);
		vis[1]=1;
		level[1]=1;

		while(!q.empty())
		{
			s=q.front();
			q.pop();

			for (int i = 0; i < v[s].size(); ++i)
			{
				if(!vis[v[s][i]])
				{
					level[v[s][i]]=level[s]+1;
					vis[v[s][i]]=1;
					q.push(v[s][i]);
				}
			}
		}
		for (int i = 1; i <=n; ++i)
		{
			if(level[i]==x)
				count++;
		}
		return count;
}

int dabra(vector<vector<int> >v)
{
	int n=v.size(),s;
	int dis[n];
	for (int i = 0; i <= n; ++i)
		dis[i]=MAX;

	deque<int> q;
	q.push_front(1);
	dis[1]=0;

	while(!q.empty())
	{
		s=q.front();
		q.pop_front();

		for (int i = 1; i < v[s].size(); ++i)
		{
			if(dis[v[s][i]] > dis[s]+1)
			{
				dis[v[s][i]] = dis[s]+1;
				q.push_back(v[s][i]);	
			}
		}
	}

	return dis[n-1];

}

int main()
{
	ios_base::sync_with_stdio(0); 

	int n,a,b,x,t,m;
	cin>>t;
	while(t--)
	{
	cin>>n>>m;
	//cout<<n<<" "<<m<<"\n";
	vector<vector<int> > v(n+1);
	for (int i = 0; i <=n; ++i)
	{
		for (int j = 0; j <=n; ++j)
		{
			v[i][j]=0;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <=n; ++i)
	{
		for (int j = 1; j <v[i].size(); ++j)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<v.size();
	//cout<<dabra(v)<<endl;
}
		


	return 0;
}