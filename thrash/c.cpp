/*input
2
1000000000 100000000000000000
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long int
using namespace std;


    vector<vector<int> > p;

void pri(ll n,int j)
{
	
	while(n%2==0)
	{
		p[j].push_back(2);
		n/=2;
	}

   for (int i = 3; i*i <= n; i+=2)
   {
   		if(n%i==0)
   		{
   			p[j].push_back(i);
   			n/=i;
   		}
   }

   if(n>2)
   		p[j].push_back(n);
}
int main() {
    /* Enter your code here. Read input from STDIN. Prll output to STDOUT */
    ll n;
 
    cin>>n;
    p.clear();
    p.resize(n);
   	map<int,int> m;

    vector<ll> v(n);
    ll k,l=0;
    for(ll i=0;i<n;i++)
    {    cin>>v[i];
     	pri(v[i],i);
     //p[i].second=i;     
    }
    for (int i = 0; i < n; ++i)
    {	for (int j = 0; j < p[i].size(); ++j)
    {
    	cout<<p[i][j]<<" ";
    }
    cout<<"\n";
    }
    cout<<"\n";
   // sort(p.begin(),p.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
        	for(int o=0;o<p[i].size();o++)
          		m[p[i][o]]++;
          	for(int o=0;o<p[j].size();o++)
          		m[p[j][o]]++;
          	k=1;
          	for(auto it=m.begin();it!=m.end();++it)
          		{//cout<<it->first<<" "<<it->second<<" ";
          		k*=it->second+1;
          	}

          	cout<<k<<"\n";
          	m.clear();
          	l=max(l,k);
			/*k=v[i]*v[j];
			cout<<k<<" ";
			
			 k=pri(k);
			cout<<k<<" ";
            m=max(m,k);
            cout<<m<<"\n";*/
        }
    }
    cout<<l<<endl;
    //cout<<(v[p[n-1].second]*v[p[n-2].second])<<endl;
    return 0;
}