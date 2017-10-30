/*input
12
-1 -1 -1 -1 0 0 0 0 1 1 1 1
0

58 9 -8 -10 -7 7 -8 2 -7 4 7 0 -3 -4 -5 -1 -4 5 8 1 9 -2 5 10 -5 -7 -1 -6 4 1 -5 3 8 -4 -10 -9 -3 10 0 7 9 -8 10 -9 7 8 0 6 -6 -7 6 -4 2 0 10 1 -2 5 -2
0
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<vector<int> > fourSum(vector<int> &A, int B) {
   // set<int> s;
   // for(int i=0;i<A.size();i++)
    //s.insert(A[i]);
   // A.clear();
  //  for(auto it:s)
  //  A.push_back(it);
  sort(A.begin(),A.end());
    map<int,pair<int,int> > m;
    vector<vector<int> > ans;
    vector<int> v,cc(4);
    int n=A.size(),c=0;
    for(int i=0;i<A.size();i++)
    	if(A[i]==0)
    		c++;
    if(c>=4)
    	{c=1;
    		cc[0]=cc[1]=cc[2]=cc[3]=0;}
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
       		// cout<<A[i]<<" "<<A[j]<<" "<<A[i]+A[j]<<" "<<B-A[i]-A[j]<<"\n";
           m[A[i]+A[j]]=(make_pair(A[i],A[j]));
       }
    }
    cout<<"map\n";
    for(auto it:m)
    {
    	cout<<it.first<<" ";
    	// for(int k=0;k<it.second.size();k++)
    	cout<<it.second.first<<" "<<it.second.second<<"\n";
    }
        cout<<"map kahtam \n";
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
       		 cout<<"--->"<<A[i]<<" "<<A[j]<<"\n";
       	if(m[A[i]+A[j]].first==0)
       		continue;
       		  if(m[B-A[i]-A[j]].first!=0)
           {
               
               v.push_back(A[i]);
               v.push_back(A[j]);
               v.push_back(m[B-A[i]-A[j]].first);
               v.push_back(m[B-A[i]-A[j]].second);
               sort(v.begin(),v.end()); 
               if(v[0]>0 && c==1)
               {ans.push_back(cc);
               	cc.clear();
               	c=0;}             
               ans.push_back(v);
               v.clear();

               cout<<A[i]<<" "<<A[j]<<" ";
               for (int l = 0; l < 4; ++l)
               {
               	cout<<ans[ans.size()-1][l]<<" ";
               }
               cout<<"\n";
               m[B-A[i]-A[j]].first=0;
               m[B-A[i]-A[j]].second=0;
               m[A[i]+A[j]].first=0;
               m[A[i]+A[j]].second=0;
           
       }
          
           
       }
    }
    if(c==1)
    	ans.push_back(cc);
  

    return ans;
    
}

int main()
 {
    ios_base::sync_with_stdio(0);

   	int n,k;
   	cin>>n;
   	std::vector<int> v(n);
   	std::vector<std::vector<int> > a;
   for (int i = 0; i < n; ++i)
   {
   		cin>>v[i];
   }
   cin>>k;
   a=fourSum(v,k);
   // sort(a.begin(),a.end());
   cout<<a.size();
   cout<<"*************************\n";
   for (int i = 0; i < a.size(); ++i)
   {
   	for (int j = 0; j < a[i].size(); ++j)
   	{
   		cout<<a[i][j]<<" ";
   	}
   	cout<<"\n";
   }

  	return 0;

 }