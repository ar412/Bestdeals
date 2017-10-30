/*input
10 5 14
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
	int n,m,t;
	cin>>n>>m>>t;
	int k=m;
	
int s=min(t,n);
int sit=max(t-k,0);
cout<<s-sit;

    return 0;
}
/*

if(t<=k)
 	{
 		cout<<t;
 	}
 	else if(k<t && t<=n)
 	{
 		cout<<k;
 	}
 	else	if(n<t && t<=n+k) 
 		cout<<k+n-t;
 	else cout<<0;

*/