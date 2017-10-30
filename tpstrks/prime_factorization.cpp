
vector<vector<int> > p;

void prime(int n,int j)
{	while(n%2==0)
	{
		p[j].push_back(2);
		n/=2;
	}
	while(i*i<=n)
	{
	if(n%i==0)
		{
	   		p[j].push_back(i);
	   		n/=i;
	   	}
	else i+=2;
	}
	if(n>2)
		p[j].push_back(n);

}