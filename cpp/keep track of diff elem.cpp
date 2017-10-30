/*input
10 9
1 2
1 3
4 5
4 6
4 7
8 9
7 8
9 10
1 10
*/

#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;

vector<int> ar;
vector<int> sz;
set<int> s;
map<int,int> m;
int ans;

int root(int x)
{
	while(ar[x]!=x)
		x=ar[x];
	return x;
}

void un(int x,int y)
{
	int a=root(x);
	int b=root(y);
	

	if(a!=b)
	{	
		if(sz[a]>sz[b])
			swap(a,b);

		ar[a]=b;
		m[sz[a]]--;
		m[sz[b]]--;

		if(!m[sz[a]])
			s.erase(sz[a]);
		if(!m[sz[b]])
			s.erase(sz[b]);

		sz[b]+=sz[a];

		m[sz[b]]++;
		s.insert(sz[b]);

		ans=INT_MAX;
		int l=-1;
		for (auto it:s)
		{
			//cout<<*it<<" ";
			if(m[it]>1)
				{ans=0;
				break;}

			if(l!=-1)
				ans=min(ans,(it)-l);

			l=it;
		}
		
		//cout<<ans<<endl;		

		if(ans==INT_MAX)
			ans=0;
	}

}

 int main()
 {
 	int n,q,a,b;
	
	s.insert(1);

 	cin>>n>>q;

 	ar.clear();
 	sz.clear();
 	ar.resize(n+1);
 	sz.resize(n+1);
 	
 	for (int i = 1; i <= n; ++i)
 	{
 		ar[i]=i;
 		sz[i]=1;
 		m[1]++;
 	}

  	for (int i = 0; i < q; ++i)
 	{
 				cin>>a>>b;

 				// cout<<i+1<<"\n";
 				un(a,b); 
 				cout<<ans<<endl;		

 	}


 	return 0;
 }



