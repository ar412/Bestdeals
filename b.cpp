/*input
2 40 50

*/

#include <bits/stdc++.h>
#define ll long long int 
#define mod 1000000007
using namespace std;
 
int sumofd(int a)
{
	int sum=0;
	while(a!=0)
	{
		sum+=a%10;
		a=a/10;
	}
	return sum;
}



int main()
{	
	
	int n,a,d,r,m=INT_MIN,c=0,ma=INT_MIN;
	cin>>n;
	map<int,int > s;

	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		d=sumofd(a);
		r=a^d;
		//cout<<r<<" ";
		if(s.find(r)==s.end())
			s[r]=1;
		else  {
			c++;
			int f=s[r];
			s[r]=f+1;
		}
	}
	if(c==0){
	for (auto i=s.begin();i!=s.end();i++)
	{
			if(((*i).first)>m)
			{
				m=(*i).first;
			}
	
	}}
	else {
			for (auto i=s.begin();i!=s.end();i++)
	{
			if((*i).second>ma)
			{
				ma=(*i).second;
				m=(*i).first;
			}
	
	}
	}
	cout<<m<<" "<<c;
    return 0;
}


//1000%107 0 

