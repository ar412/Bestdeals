/*input
1
m
*/
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
   ios_base::sync_with_stdio(0);
   int t;
   cin>>t;
   while(t--)
   {
   	string s;
   	cin>>s;

   	int n=s.size(),cs=0,cm=0;
   	
   	int a[n];

   	for (int i = 0; i < n; ++i)
   	{
   		a[i]=0;
   	}

   	
   for (int i = 0; i < n; ++i)
   {
   		if(s.at(i)=='s')
   			cs++;
   		if(s.at(i)=='m')
   		{	
   			cm++;

   			if(i==n-1)
   				{
   				if(s.at(i-1)=='s' && a[i-1]==0)
   				{cs--;a[i-1]=1;}
   				}
			else if(i==0)
				{
				if(s.at(i+1)=='s' && a[i+1]==0)
   				{cs--;a[i+1]=1;}
   				}
   			else if(i>0 && i<n-1)
   					{
   				if(s.at(i+1)=='s' && a[i+1]==0)
   				{cs--;a[i+1]=1;}
   				else if(s.at(i-1)=='s' && a[i-1]==0)
   				{cs--;a[i-1]=1;}
   				}
   		}

   	}
   //	cout<<cs<<" "<<cm<<endl;
   		if(cs==cm)
   			cout<<"tie"<<endl;
   		else if(cs<cm)
   			cout<<"mongooses"<<endl;
   		else cout<<"snakes"<<endl;
   

   	}	
   	
    return 0;
}