/*input
700
9307216756404590162143344901558545760612901767837570518638460182990196397856220673189163417019781185
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;
	

 int main()
 {
 	ios_base::sync_with_stdio(0);
 	ll s=0,n,k,ma=-1,c=0;
 	string nn;
 	ll a[10],b[10];
 	for (int i = 0; i < 10; ++i)
 	{
 		a[i]=0;
 	}

 	cin>>k>>nn;

 	for(int i=0;i<nn.size();i++)
 	{
 		n=nn.at(i)-'0';
 		//cout<<n<<" ";
 		s+=n;
 		a[n]++;
 	}
 	//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<"\n ";
 	for (int i = 0,j=9; i < 10; ++i,j--)
 	{
 		b[j]=a[i];
 	}
 	for (int i = 0; i < 10; ++i)
 	{
 		//cout<<b[i]<<" ";
 		if(b[i]>0)
 			ma=i;
 	}
 	//cout<<ma<<" \n";
 	if(s>=k)
 		cout<<0<<endl;
 	else{
 		s=k-s;
 		//cout<<s;
 		while(s>0)
 		{
 			s-=ma;
 			//cout<<b[ma]<<" ";
 			c++;
 			b[ma]--;
 			if(b[ma]<=0)
 			{
 				for (int i = ma; i >=0; i--)
 				{
 					if(b[i]>0)
 						{ma=i;break;}
 				}
 			}
 			//cout<<c<<" "<<b[ma]<<" "<<ma<<"\n";
 		}
 		cout<<c<<endl;
 	}
 	
 	return 0;
 }	
