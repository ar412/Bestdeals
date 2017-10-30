/*input
1 1 1 8
*/
// 0 0 0 0 0 0 wala
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	int ar[26];
	for (int i = 0; i < 26; ++i)
	{
		ar[i]=0;
	}
	int a,b;
	ll l,r;
	cin>>a>>b>>l>>r;
	string s;
	for (int i = 0; i < a; ++i)
	{
		s+=i+'a';
	}
	for (int i = 0; i < b; ++i)
	{
		s+='@';
	}
	int j=3;
	while(j>0)
{	for (int i = 0; i < a; ++i)
	{
		s+=i+a+'a';
	}
	for (int i = 0; i < b; ++i)
	{
		s+='@';
	}
	j--;
}
	cout<<s<<endl;
	l--;
	r--;
	int f=r-l;
	if(r-l>a)
		f=1;

	int n=a+b,c=0;
	if(l<n)	l=l%n;
	else	l=l%n+n;



	if(r<n)	r=r%n;
	else {
		
		r=(r%n)+n+n;
		
}
//cout<<a<<" "<<b<<endl;


	if(r<l)
		r=r+n;

	
		
	cout<<l<<" "<<r<<endl;

	for (int i = l; i <= r; ++i)
	{
		if(s.at(i)!='@')
		ar[s.at(i)-'a']++;
	}
	for (int i = 0; i < 26; ++i)
	{
		if(ar[i]>0)
			c++;
	}
	if(c==0)
		cout<<1;
	else 
	cout<<c;

	/*abcd aa e(fgh) aa efgh  l<a  ans+= a-l

	3 7 4 6
	 abc aaaaaaa */


	return 0;
}