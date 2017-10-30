/*input
100 
4
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
 	int n,s,sum,f=0;
 	cin>>s>>n;
 	int a[n];
 	for (int i = 0; i < n; ++i)
 	{
 		cin>>a[i];
 	}

 	for (int i = 0; i < pow(2,n); ++i)
 	{
 		sum=0;
 		for (int j = 0; j < n; ++j)
 		{
 			if(i&(j>>1))
 				sum+=a[i];
 		}
 		cout<<sum<<" ";
 	
 	}
 	if(f==1)
 	cout<<"yes";
 	return 0;
 }
 
