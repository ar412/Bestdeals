/*input
4 1
4 22 7 10
16
*/
2 2 2 2
2 4 8 16

2 3 6 7 14 42
2 3 7
/*4
4 3 2 1
3
42 489 16*/
#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int 
using namespace std;


#define MAXN   1000001
 
int spf[MAXN],a[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
 
        spf[i] = i;
 
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
 
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
/*
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
*/
vector<int> pd(int n)
{
   
    vector<int> res;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i) 
               {// printf("%d ", i);
           if(n/i!=1)
           res.push_back(n/i);
          }
            else
            {
               // printf("%d ", i);
            	  if(i!=1)
            	res.push_back(i);
              if(n/i!=1)
                res.push_back(n/i);
            }
        }
    }
 sort(res.begin(), res.end());

 for (int i = 0; i < res.size(); ++i)
 	cout<<res[i]<<" ";
 cout<<endl;

    return res;
}
int main()
{
	 sieve();
	 for (int i = 0; i < MAXN; ++i)
	 {
	 	a[i]=0;
	 }
	int n,ar,q;
	cin>>n>>q;
	for (int i = 0; i < n; ++i)
	{
		cin>>ar;
		a[ar]=1;
	}
	
	while(q--)
	{
		int x,c=0,k=0;
		cin>>x;
		vector<int> v=pd(x);
		vector<int> p;
		//cout<<v.size()<<endl;

	
		for (int i=0; i<v.size(); i++)
        {
        //cout<<a[v[i]]<<" ";
       {	
        	if(a[v[i]]==0)
        	{
        		//cout<<spf[v[i]]<<" "<<v[i]<<endl;
        		k++;
        		 if(spf[v[i]]==v[i])
        		p.push_back(v[i]);
        	}
        	else {
        		c++;
        	}}
		}

 for (int i = 0; i < p.size(); ++i)
 	cout<<p[i]<<" ";
 cout<<endl;
 cout<<c<<endl;

		//cout<<p.size()<<endl;
		if(p.size()==0 && c>=2)
			cout<<"YES"<<endl;
		else if(p.size()==1 && c>=1)
			cout<<"YES"<<endl;
		else if(p.size()==2)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

    return 0;
}