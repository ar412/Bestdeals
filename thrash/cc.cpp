/*input
3 3
*/

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int N;
vector<vector<long double> > dp;
   
int go(int i,int j)
{
    
    go(i,k);

    
    return c;
}
int main()
 {
    ios_base::sync_with_stdio(0);
   

    int n,l,c=0,k;
    cin>>n>>l;

    dp.resize(n+1,vector<long double> (n+1,-1));
    for (int i = 1; i <=n; ++i)
    {
        k=l;
        for (int j = 1; j <= n; ++j)
        {

            if(j%i==0)
                dp[i][j]=1;
            else dp[i][j]=0;

            // int a=i;
            //      if(j%a==0)
            //         k--;a=j;j++;
            //     else j++;

            // cout<<i<<" "<<j<<" "<<k<<" "<<c<<"\n";
            // if(k<=0)
            //    {
            //     cout<<"dfvj\n";
            //  break;}
        }
        // if(k==0)
        //     c++;
    }
    for (int i = 1; i <=n; ++i)
    {
        for (int j = 1; j <=n; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    int ans=0;
    for (int i = 1; i <=n; ++i)
    {
        for (int j = 1; j <=n; ++j)
        {
            ans+=go(i,j,k);
          //  cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<ans;
    
    return 0;

 }
