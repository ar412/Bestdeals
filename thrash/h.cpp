/*input
5
1 2 3 4 4 
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<bool> dp;
int m;
// int go(vector<vector<int> > &v,int i,int j)
// {
// 	if(i==v.size()-1)
// 		return v[i][j];
// 	if(dp[i][j]!=-1)
// 		return dp[i][j];

// 	int m=0;
// 	for (int k = 0; k < v.size(); ++k)
//     {
//     	if(k!=j)
//     	m=max(m,go(v,i+1,k));
//     }
//     return dp[i][j]=m+v[i][j];
// }

int ff(string s,int i,int c,int l)
{
	if(c==0)
		m=max(m,l);
	if(i<0 && c==0)
		return l;
	if(i<0 && c!=0)
		return 0;
	// if(dp[i]!=0)
	// 	return dp[i];
	int xx=0;
	if(s[i]==')')
	{
		xx=max(xx,1+ff(s,i-1,c+1,l+1));
		xx=max(xx,ff(s,i-1,c,l));
	}
	else
	{
		xx=max(xx,1+ff(s,i-1,c-1,l+1));
		xx=max(xx,ff(s,i-1,c,l));
	}
	return dp[i]=xx;

}

int main()
 {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
    	cin>>v[i];
    }
    int a=v[0];
    
    for (int i = 0; i < n; ++i)
    {
    	
    }

    return 0;
}
    