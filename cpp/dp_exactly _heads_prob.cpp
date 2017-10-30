/*input
4
0.2 0.4 0.6 0.8
2
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int N;

    std::vector<long double> p;
    std::vector<vector<long double> > dp;
long double go(int n,int k)
{
    if(k<0)
        return INT_MIN;
    if(n==N)
        {
            if(k==0)
                return 1;
            else return INT_MIN;
         }

    if(dp[n][k]!=-1)
        return dp[n][k];
    
    long double a1=go(n+1,k-1);
    long double a2=go(n+1,k);
    long double ans=0;
    if(a1!=INT_MIN)
        ans+=a1*p[n];
    if(a2!=INT_MIN)
        ans+=a2*(1-p[n]);
    dp[n][k]=ans;
    //cout<<n<<" "<<k<<" "<<a1<<" "<<a2<<"\n";
    return dp[n][k];

}

int main()
 {
    ios_base::sync_with_stdio(0);
    
    cin>>N;
    p.clear();
    p.resize(N);
    for (int i = 0; i < N; ++i)
    {
       cin>>p[i];
    }
    int k;
    cin>>k;
    dp.resize(N+1,vector<long double> (k+1,-1));
   
    cout<<go(0,k);
    // ORRR
    // cout<<dp[0][k];
    
    // for (int i = 0; i < N; ++i)
    // {
    //     for (int j = 0; j < k; ++j)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
 
    return 0;
}