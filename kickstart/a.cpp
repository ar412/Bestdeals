/*input
1
QZHAQYCWDFANIQXBQZIDWKOBTXGJLKTQCUNJGMHOWSQHVTXZJM
*/
#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int j = 1; j <= t; ++j)
	{
		string s;
		cin>>s;
		int n=s.size();
		int a[n],b[n],c[n],flag=0;
		vector<pair<int,int> > v(n);
		for (int i = 0; i < n; ++i)
		{
			a[i]=s.at(i)-'A';
			//cout<<a[i]<<" ";
			b[i]=-1;
			c[i]=0;
		}
		//cout<<endl;
		for (int i = 0; i < n; ++i)
		{
			v[i].first=i-1;
			v[i].second=i+1;				
		}
			v[0].first=1;
			v[0].second=-1;
			v[n-1].first=n-2;
			v[n-1].second=-1;

		b[1]=a[0];
		b[n-2]=a[n-1];
		//cout<<b[1]<<" "<<b[n-2];
		for(int k=0;k<n ;k++)
		for (int i = 1; i < n-1; ++i)
		{
			

			if(	b[v[i].first]==-1 && b[v[i].second]==-1 )
				{c[i]=1;}
			else
			{
				c[i]=0;
				if(b[v[i].first]==-1)
				{if(a[i]< b[v[i].second])
					b[v[i].first]=a[i]+26-b[v[i].second];
				else b[v[i].first]=a[i]-b[v[i].second];}
				else {
					if(a[i]< b[v[i].first])
					b[v[i].second]=a[i]+26-b[v[i].first];
				else b[v[i].second]=a[i]-b[v[i].first];

				}
			}
		}
	
		for (int i = 0; i < n; ++i)
		{
			if(c[i]==1)
				flag=1;
		}
		
		if(flag==1)
			cout<<"Case #"<<j<<": AMBIGUOUS"<<endl;
		else {

			for (int i = 0; i < n; ++i)
			{
				s.at(i)=b[i]+'A';
			}
			cout<<"Case #"<<j<<": "<<s<<endl;
		}

	}

    return 0;
}