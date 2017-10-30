/*input
2

3
4 10 6
1 1 5
-5 6 8
4
5 11 4 6
3 2 10 3
1 3 1 3
4 2 8 8

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n][n], dp[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>a[i][j];

		int ans = 0;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = a[0][0];
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if(i == 0 || i-1 == j) dp[i][j] = dp[i][j-1] + a[i][j];
				else if(j == 0 || i == j-1) dp[i][j] = dp[i-1][j] + a[i][j];
				else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + a[i][j];
			}
		}
		ans += dp[n-2][n-1] + a[n-1][n-1];

		memset(dp, 0, sizeof(dp));
		dp[0][0] = a[0][0];
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(j == 0 || i == j-1) dp[i][j] = dp[i-1][j] + a[i][j];
				else if(i == 0 || i-1 == j) dp[i][j] = dp[i][j-1] + a[i][j];
				else dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + a[i][j];
			}
		}
		ans += dp[n-1][n-2];
		cout<<ans<<"\n";
	}
	return 0;
}