/*input
16 1000000007 
*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll int ex(ll int n,ll int m,ll int x)
{
    if(m==0)
    return 1;
    
    if(m%2==0)
    return ex((n*n)%x,m/2,x);
    else 
    return (n*ex((n*n)%x,(m-1)/2,x))%x;
    
}


ll int g,x,y;

void exteuc(ll int a,ll int b)
{
	if(b==0)
	{
		g=a;
		x=1;
		y=0;
	}
	else {
		exteuc(b,a%b);
		ll int temp = x;
		x=y;
		y=temp-(a/b)*y;
}
}
ll int inv(ll int n,ll int m)
{
	exteuc(n,m);
	return (x%m+m)%m;
}
int main()
{
    long long int a,b,c,m,res;
    cin>>c>>m;

    c=ex(c,m-2,m);
    cout<<c;
    cout<<
    return 0;
}
