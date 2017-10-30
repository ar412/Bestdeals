/*input
	
3
100
3
5 75 25
200
7
150 24 79 50 88 345 3
8
8
2 1 9 4 4 56 90 3
*/
#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;

ll fact(int n)
{
	if(n==1 || n==0)
		return 1;
	return n*fact(n-1);
}

int main()
{
	int n;
	cin>>n;

	for (int j = 1; j <= n; ++j)
	{

		int c,p;
		cin>>c>>p;
		int a[p];
		for (int i = 0; i < p; ++i)
				{
					cin>>a[i];
				}	

		cout<<"Case #"<<j<<": ";
	    	
				for (int i = 0; i < p; ++i)
				{
					for (int k = i+1; k < p; ++k)
					{
						if(a[i]+a[k]==c)
							{cout<<i+1<<" "<<k+1;
							break;
						}
					}
				}		
	    cout<<"\n";
	}
}