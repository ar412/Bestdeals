/*input
10 5 
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define MAX 100001
using namespace std;

int main()
{
	int n,a,b,c=0,d=0,e,k,i;
	cin>>n>>k;

	cout<<n-k+1<<endl;
	for ( i = 1; i <= n-k+1; ++i)
	{
		cout<<i<<" "<<i+1<<"\n";
	}
	i++;
	for (int j = 2; j <= k-1; ++j)
	{
		cout<<j<<" "<<i<<"\n";
		i++;
	}



	return 0;
}