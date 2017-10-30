/*input
baaabaacba
3
*/

#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
 
int main()
{	
	string s;
	int k,n;
	cin>>s>>k;
	map<char,int> m;
	n=s.length();
	for (int i = 0; i < n; ++i)
	{
		m[s.at(i)]++;
	}
	for (int i = 0; i < n; ++i)
	{
		if(m[s.at(i)]>=k)
			cout<<s.at(i);
	}
	
    return 0;
}


//1000%107 0 

