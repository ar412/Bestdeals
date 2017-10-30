bool mycomp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.first > b.first)
		return false;
	else if(a.first==b.first)
			{
				if(a.second>b.second)
					return true;
				else return false;
			}
	else if(a.first<b.first)
			return true;

}