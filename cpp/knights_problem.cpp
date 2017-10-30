/*input
8 8 1 1 8 8
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;


bool isinside(int i,int j,int n,int m)
{
  return i>=0 && j>=0 && i<n && j<m; 
}

int knight(int N, int M, int x1, int y1, int x2, int y2) {
int c=0;
int a=x1,b=y1,d1=x2,d2=y2,n=N,m=M;
  if(d1==a && d2==b)
    return 0;

  int x[]={2,2,-2,-2,1,-1,1,-1};
  int y[]={1,-1,1,-1,2,2,-2,-2};

  queue<pair<pair<int,int>,int> > q;
  q.push(make_pair(make_pair(a,b),0));
  map<pair<int,int>,int> seen;
  seen[make_pair(a,b)]=1;

  while(!q.empty())
  {
    pair<pair<int,int>,int> t= q.front();
    cout<<t.first.first<<" "<<t.first.second<<"\n";
   	if(t.first.first==x2 && t.first.second==y2) return t.second;
    q.pop();

    for (int i = 0; i < 8; ++i)
    {
      int s1=t.first.first+x[i];
      int s2=t.first.second+y[i];
      //cout<<s1<<" "<<s2<<"\n";
      c++;
      if(s1>=0 && s1<n && s2>=0 && s2<m && !seen[make_pair(s1,s2)]){
          q.push(make_pair(make_pair(s1,s2),t.second+1));
          seen[make_pair(s1,s2)]=1;
        }

    }

  }

  return -1;
    
}



int main()
 {
    ios_base::sync_with_stdio(0);
    
    int n,m,a,b,d1,d2;
    cin>>n>>m>>a>>b>>d1>>d2;

    cout<<knight(n,m,a,b,d1,d2);



    return 0;

 }
