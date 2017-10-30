/*input
3
10 7 19
45
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main()
{
    int n,m;
    ll k,ma=0;
    cin>>n;
    vector<pair<int,int> > a(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i].first;
        a[i].second=i+1;
    }
    cin>>k;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        //cout<<a[i].first<<" "<<a[i].second<<" ";
        if(k<a[i].first*a[i].second)
        {
            m=k/a[i].first;
            k=k-m*a[i].first;
            ma+=m;
            //cout<<m<<" "<<k<<endl;
        }
        else
        {
            k=k-a[i].first*a[i].second;
            ma+=a[i].second;
            //cout<<a[i].second<<" "<<k<<endl;
        }
    }

    cout<<ma;

    return 0;
}  