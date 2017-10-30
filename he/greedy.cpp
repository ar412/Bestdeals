/*input
1
5
11 111 223 26 1
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

 int main()
 {
 	ios_base::sync_with_stdio(0); 

 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n,f=0,c=0;
 		ll x;
 		cin>>n;
 		ll a[n];
 		for (int i = 0; i < n; ++i)
 		{
 			cin>>a[i];
 		}
 		if(n==1)
 			cout<<"1 0\nMotu\n";
 		else {
 		int i=0,j=n-1,mc=0,pc=0;
 		int m;///=a[0];
 		int p;//=a[j];
 		//cout<<i<<" "<<j<<" "<<m<<" "<<p<< " "<<mc<<" "<<pc<<"\n";
 		while(i<=j)
 		{
 			if(m<p*2)
 				{m+=a[i];i++;mc++;}
 			else if(m>p*2)
 					{m-=p*2;j--;pc++;p=a[j];}
 			else if(m==p*2)
 					{i++,m=a[i+1],mc++;
 						if(i!=j)
 							p=a[j-1],j--,pc++;
 					} 					

 		}

 		cout<<mc<<" "<<pc<<endl;
 		if(mc>pc)
 			cout<<"Motu\n";
 		else if(mc<pc)
 			cout<<"Patlu\n";
 		else cout<<"Tie\n";
 		}
 		/*sort(a,a+n);
 		for(int i=0;i<n;i++)
 		{
 			f+=a[i];
 			if(f<=x)
 				c++;
 			else break;
 		}
 		cout<<c<<endl;*/
 	}
 
 	return 0;
 }
 
