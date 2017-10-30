#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s,s1;
	
	int n,k;
	cin>>n>>k;
	cin>>s1;
	for (int i = 0; i < k; ++i)
	{
		s.append(s1);
	}

	int a[s.length()],b[s.length()];
for (int i = 0; i < s.length(); ++i)
{
	a[i]=0;b[i]=0;
}

//	cout<<"n= "<<n<<cout;
//	cout<<"s= "<<s1<<endl;
/*	cout<<"b= ";
	for (int i = 0; i < s.length(); ++i)
{
	cout<<i<<"i "<<b[i]<<endl;
}*/
	//
	
	
//	cout<<"for 1";
	for (int i = 0; i < s.length(); ++i)
	{
		if (s.at(i)=='a')
		{
			a[i]=1;
			//cout<<"i  "<<i<<endl;
		}
		else if (s.at(i)=='b')
		{
			for (int j = 0; j < i; ++j)
			{
				if(a[j]==1) 
					{
						b[j]++;
						//cout<<"j "<<j<<endl;
					}
			}
		}
	}
/*	cout<<"b= ";
for (int i = 0; i < s.length(); ++i)
{
	cout<<i<<"i "<<b[i]<<endl;
}
	cout<<"for 2"<<endl;*/
	int count=0;
	for (int i = 0; i < s.length(); ++i)
	{
		count+=b[i];
	}
	cout<<"c= "<<count<<endl;

}
return 0;

}